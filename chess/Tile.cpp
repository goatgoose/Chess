//
//  Tile.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Tile.hpp"

Tile::Tile(int x, int y, int scale, TileColor color) {
    this->x = x;
    this->y = y;
    this->scale = scale;
    this->color = color;
    
    rect = new RectangleShape();
    if (color == WHITE) {
        rect->setFillColor(Color(246, 246, 246));
    } else {
        rect->setFillColor(Color(75, 75, 75));
    }
    update();
}

void Tile::setScale(int scale) {
    this->scale = scale;
    update();
}

void Tile::update() {
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

RectangleShape* Tile::getRect() {
    return this->rect;
}

Tile::~Tile() {
    delete this->rect;
}

