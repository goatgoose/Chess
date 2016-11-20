//
//  Coordinate.cpp
//  chess
//
//  Created by Sam Clark on 11/20/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Coordinate.hpp"

Coordinate::Coordinate(int x, int y) {
    this->x = x;
    this->y = y;
}

int Coordinate::getX() {
    return this->x;
}

int Coordinate::getY() {
    return this->y;
}
