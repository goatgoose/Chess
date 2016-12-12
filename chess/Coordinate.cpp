//
//  Coordinate.cpp
//  chess
//
//  Created by Sam Clark 
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
