//
//  Clickable.cpp
//  chess
//
//  Created by Sam Clark on 11/22/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Clickable.hpp"
#include "ChessWindow.hpp"

Clickable::Clickable(ChessWindow* window) {
    this->window = window;
    this->window->addClickable(this);
}

Clickable::~Clickable() {
    this->window->removeClickable(this);
}

bool Clickable::isInBounds(int x, int y) {
    return (x > getX1() &&
            x < getX2() &&
            y > getY1() &&
            y < getY2());
}

void Clickable::pressEvent() {
    
}

void Clickable::releaseEvent() {
    
}

void Clickable::hoverEvent() {
    
}

void Clickable::unhoverEvent() {
    
}
