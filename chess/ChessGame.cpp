//
//  ChessGame.cpp
//  chess
//
//  Created by Sam Clark on 12/2/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessGame.hpp"

ChessGame::ChessGame(int scale): ChessWindow(scale + 200, scale, Color(0, 0, 0)) {
    this->board = new ChessBoard(scale, this);
    this->pickedUpPiece = nullptr;
    this->pickedUpPieceTile = nullptr;
}

void ChessGame::resizeEvent(Event event) {
    this->board->setScale(event.size.height);
}
