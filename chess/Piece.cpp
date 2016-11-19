//
//  Piece.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Piece.hpp"

Piece::Piece(int x, int y, int scale, string side, string textureName) {
    this->x = x;
    this->y = y;
    this->scale = scale;
    this->side = side;
    
    texture = new Texture();
    texture->loadFromFile(resourcePath() + textureName + "-" + side + ".png");
    sprite = new Sprite(*texture);
    update();
}

void Piece::setScale(int scale) {
    this->scale = scale;
    update();
}

void Piece::update() {
    sprite->setScale(Vector2f(0.35, 0.35));
    sprite->setPosition(Vector2f(scale * x + scale / 5, scale * y + scale / 7));
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
