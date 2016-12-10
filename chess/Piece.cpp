//
//  Piece.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Piece.hpp"
#include "ChessGame.hpp"
#include "ChessBoard.hpp"

Piece::Piece(int x, int y, Player* player, string textureName) {
    this->x = x;
    this->y = y;
    this->player = player;
    
    this->board = player->board;
    this->side = player->getSide();
    
    texture = new Texture();
    texture->loadFromFile(resourcePath() + textureName + "-" + player->getSideString() + ".png");
    sprite = new Sprite(*texture);
    player->board->game->addDrawable(sprite);
    
    update();
}

void Piece::update() {
    int scale = board->getOffset();
    double pieceScale = (double) scale / 320;
    sprite->setScale(Vector2f(pieceScale, pieceScale));
    
    int xPos = (scale * x) + ((scale / 2) - (sprite->getGlobalBounds().width / 2));
    int yPos = (scale * y) + ((scale / 2) - (sprite->getGlobalBounds().height / 2));
    sprite->setPosition(Vector2f(xPos, yPos));
}

void Piece::moveTo(Tile* tile) {
    board->tiles[this->x][this->y]->piece = nullptr;
    this->x = tile->getX();
    this->y = tile->getY();
    tile->piece = this;
    
    // capture enemy piece if it lands on it
    
    update();
    
    ChessServerAPI::movePiece(player, "1a", "2b", [&] {
        cout << "moved piece" << endl;
    });
}

bool Piece::moveIsPossible(Coordinate move) {
    Tile* tile = board->getTile(move);
    
    // check for out of bounds
    if (tile == nullptr) {
        return false;
    }
    
    // does a piece exist
    if (tile->piece != nullptr) {
        if (tile->piece->getSide() == this->side) {
            // if its on this team u cant move here
            return false;
        }
    }
    
    // check if king will die
    
    return true;
}

bool Piece::moveIsPossible(Tile* tile) {
    if (tile == nullptr) {
        return false;
    }
    return moveIsPossible(Coordinate(tile->getX(), tile->getY()));
}

Sprite* Piece::getSprite() {
    return this->sprite;
}

Side Piece::getSide() {
    return this->side;
}

Piece::~Piece() {
    delete texture;
    delete sprite;
}
