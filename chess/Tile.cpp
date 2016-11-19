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

Tile::Tile(int x, int y, TileColor color) {
    this->x = x;
    this->y = y;
    this->color = color;
    this->rect = RectangleShape();
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

RectangleShape Tile::getRect() {
    rect.setSize(Vector2f());
}

