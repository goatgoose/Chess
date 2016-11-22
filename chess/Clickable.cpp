//
//  Clickable.cpp
//  chess
//
//  Created by Sam Clark on 11/22/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Clickable.hpp"
#include "ChessGame.hpp"

Clickable::Clickable() {
    ChessGame::addClickable(this);
}

Clickable::~Clickable() {
    ChessGame::removeClickable(this);
}
