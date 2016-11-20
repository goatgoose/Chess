//
//  Player.cpp
//  chess
//
//  Created by Sam Clark on 11/20/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Player.hpp"
#include "ChessBoard.hpp"

Player::Player(Side side, ChessBoard* board) {
    this->side = side;
    this->board = board;
}

Side Player::getSide() {
    return this->side;
}

string Player::getSideString() {
    if (this->side == WHITE) {
        return "white";
    } else {
        return "black";
    }
}
