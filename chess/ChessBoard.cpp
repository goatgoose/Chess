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
                tiles[x][y] = new Tile(x, y, WHITE, this);
            } else {
                tiles[x][y] = new Tile(x, y, BLACK, this);
            }
            tileIsWhite = !tileIsWhite;
        }
        tileIsWhite = !tileIsWhite;
    }
}

void ChessBoard::createPieces() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            tiles[x][y]->piece = nullptr;
        }
    }
    
    for (int x = 0; x < 8; x++) {
        tiles[x][1]->piece = new Pawn(x, 1, getOffset(), "black");
        tiles[x][6]->piece = new Pawn(x, 6, getOffset(), "white");
    }
}

void ChessBoard::update() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            tiles[x][y]->update();
            if (tiles[x][y]->piece != nullptr) {
                tiles[x][y]->piece->setScale(getOffset());
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
