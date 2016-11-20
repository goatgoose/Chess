//
//  Tile.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Tile.hpp"
#include "ChessBoard.hpp"

Tile::Tile(int x, int y, TileColor color, ChessBoard* board) {
    this->x = x;
    this->y = y;
    this->board = board;
    this->color = color;
    
    rect = new RectangleShape();
    if (color == WHITE) {
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

TileColor Tile::getColor() {
    return this->color;
}

Tile::~Tile() {
    delete this->rect;
}

