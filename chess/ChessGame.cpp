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
    
    Button* testButton = new Button(0.8, 0.5, 100, 100, this, [&] {cout << "test" << endl;});
    testButton->setColor(Color(95, 183, 96));
}

void ChessGame::resizeEvent(Event event) {
    this->board->setScale(event.size.height);
}
