//
//  Board.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessBoard.hpp"

ChessBoard::ChessBoard() {
    createTiles(false);
}

void ChessBoard::createTiles(bool alreadyExists = true) {
    bool tileIsWhite = true;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (alreadyExists) {
                delete tiles[x][y];
            }
            
            if (tileIsWhite) {
                tiles[x][y] = new Tile(x, y, WHITE);
            } else {
                tiles[x][y] = new Tile(x, y, BLACK);
            }
            tileIsWhite = !tileIsWhite;
        }
    }
}

void ChessBoard::setScale(int scale) {
    this->scale = scale;
}

int ChessBoard::getOffset() {
    return this->scale / 8;
}
