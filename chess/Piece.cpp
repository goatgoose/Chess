//
//  Piece.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Piece.hpp"

Piece::Piece(int x, int y, int scale, PieceSide side) {
    this->x = x;
    this->y = y;
    this->scale = scale;
    this->side = side;
}

Piece::~Piece() {
    delete texture;
    delete sprite;
}

void Piece::moveTo(int x, int y) {
    sprite->setPosition(Vector2f(scale * x, scale * y));
}
