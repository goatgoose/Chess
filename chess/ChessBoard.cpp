//
//  Board.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessBoard.hpp"

ChessBoard::ChessBoard(int scale) {
    this->scale = scale;
    
    createTiles();
    createPieces();
}

void ChessBoard::createTiles() {
    bool tileIsWhite = true;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (tileIsWhite) {
                tiles[x][y] = new Tile(x, y, getOffset(), WHITE);
            } else {
                tiles[x][y] = new Tile(x, y, getOffset(), BLACK);
            }
            tileIsWhite = !tileIsWhite;
        }
        tileIsWhite = !tileIsWhite;
    }
}

void ChessBoard::createPieces() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            pieces[x][y] = nullptr;
        }
    }
    
    for (int x = 0; x < 8; x++) {
        pieces[x][1] = new Pawn(x, 1, getOffset(), "black");
        pieces[x][6] = new Pawn(x, 6, getOffset(), "white");
    }
}

void ChessBoard::update() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            tiles[x][y]->setScale(getOffset());
            if (pieces[x][y] != nullptr) {
                pieces[x][y]->setScale(getOffset());
            }
        }
    }
}

void ChessBoard::setScale(int scale) {
    this->scale = scale;
    update();
}

int ChessBoard::getOffset() {
    return this->scale / 8;
}
