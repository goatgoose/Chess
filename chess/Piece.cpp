//
//  Piece.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Piece.hpp"
#include "ChessBoard.hpp"

Piece::Piece(int x, int y, string side, string textureName, ChessBoard* board) {
    this->x = x;
    this->y = y;
    this->side = side;
    this->board = board;
    
    texture = new Texture();
    texture->loadFromFile(resourcePath() + textureName + "-" + side + ".png");
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

void Piece::moveTo(int x, int y) {
    this->x = x;
    this->y = y;
    update();
}

Sprite* Piece::getSprite() {
    return this->sprite;
}

Piece::~Piece() {
    delete texture;
    delete sprite;
}
