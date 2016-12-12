//
//  Player.cpp
//  chess
//
//  Created by Craig Conway
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
