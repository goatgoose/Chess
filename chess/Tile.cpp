//
//  Tile.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Tile.hpp"
#include "ChessBoard.hpp"
#include "ChessGame.hpp"

Tile::Tile(int x, int y, Side side, ChessBoard* board) {
    this->x = x;
    this->y = y;
    this->board = board;
    this->side = side;
    
    this->clickable = new Clickable([&]{ this->clickEvent(); }, "tile:" + to_string(x) + "," + to_string(y));
    board->game->addClickable(this->clickable);
    
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
    
    clickable->x1 = scale * x;
    clickable->y1 = scale * y;
    clickable->x2 = clickable->x1 + scale;
    clickable->y2 = clickable->y1 + scale;
}

void Tile::clickEvent() {
    cout << "click for: " << x << ", " << y << endl;
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

