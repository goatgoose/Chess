//
//  Board.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessBoard.hpp"
#include "ChessGame.hpp"

ChessBoard::ChessBoard(int scale, ChessGame* game) {
    this->scale = scale;
    this->game = game;
    
    this->whitePlayer = new Player(WHITE, this);
    this->blackPlayer = new Player(BLACK, this);
    
    createTiles();
    createPieces();
}

void ChessBoard::createTiles() {
    bool tileIsWhite = true;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            Side side;
            if (tileIsWhite) {
                side = WHITE;
            } else {
                side = BLACK;
            }
            tiles[x][y] = new Tile(x, y, side, this);
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
        tiles[x][1]->piece = new Pawn(x, 1, whitePlayer);
        tiles[x][6]->piece = new Pawn(x, 6, blackPlayer);
    }
    
    tiles[0][0]->piece = new Rook(0, 0, whitePlayer);
    tiles[7][0]->piece = new Rook(7, 0, whitePlayer);
    tiles[0][7]->piece = new Rook(0, 7, blackPlayer);
    tiles[7][7]->piece = new Rook(7, 7, blackPlayer);
}

void ChessBoard::update() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            tiles[x][y]->update();
            if (tiles[x][y]->piece != nullptr) {
                tiles[x][y]->piece->update();
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

Tile* ChessBoard::getTile(Coordinate coordinate) {
    // check if out of bounds
    if (coordinate.getX() > 7 ||
        coordinate.getX() < 0 ||
        coordinate.getY() > 7 ||
        coordinate.getY() < 0) {
        
        return nullptr;
    }
    return tiles[coordinate.getX()][coordinate.getY()];
}
