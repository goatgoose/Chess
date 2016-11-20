//
//  Tile.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Tile.hpp"
#include "ChessBoard.hpp"

Tile::Tile(int x, int y, Side side, ChessBoard* board) {
    this->x = x;
    this->y = y;
    this->board = board;
    this->side = side;
    
    rect = new RectangleShape();
    if (side == WHITE) {
        rect->setFillColor(Color(246, 246, 246));
    } else {
        rect->setFillColor(Color(75, 75, 75));
    }
    update();
}

void Tile::update() {
    int scale = board->getOffset();
    rect->setSize(Vector2f(scale, scale));
    rect->setPosition(Vector2f(scale * x, scale * y));
}

int Tile::getX() {
    return this->x;
}

int Tile::getY() {
    return this->y;
}

Side Tile::getSide() {
    return this->side;
}

Tile::~Tile() {
    delete this->rect;
}

