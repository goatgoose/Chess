//
//  Tile.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Tile.hpp"
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>

Tile::Tile(int x, int y, int scale, TileColor color) {
    this->x = x;
    this->y = y;
    this->scale = scale;
    this->color = color;
    
    rect = new RectangleShape();
    rect->setSize(Vector2f(scale, scale));
    rect->setPosition(Vector2f(scale * x, scale * y));
    if (color == WHITE) {
        rect->setFillColor(Color(255, 255, 255));
    } else {
        rect->setFillColor(Color(0, 0, 0));
    }
}

Tile::~Tile() {
    delete this->rect;
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

