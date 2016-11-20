//
//  Piece.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Piece.hpp"
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
    
    update();
}

bool Piece::moveIsPossible(Coordinate move) {
    Tile* tile = board->tiles[move.getX()][move.getY()];
    
    // check for out of bounds
    if (tile == nullptr) {
        return false;
    }
    
    // does a piece exist
    if (tile->piece != nullptr) {
        if (tile->getSide() == this->side) {
            // if its on this team u cant move here
            return false;
        } else {
            // if its on this team make sure its this one
            if (tile->getX() != move.getX() || tile->getY() != move.getY()) {
                return false;
            }
        }
    }
    
    // check if king will die
    
    return true;
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
