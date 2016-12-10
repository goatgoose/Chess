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
    
    // get this from server when joining or creating game
    this->me = whitePlayer;
    
    if (this->me->getSide() == WHITE) {
        this->isMyTurn = true;
    } else {
        this->isMyTurn = false;
    }
    
    createTiles();
    createPieces();
}

void ChessBoard::createTiles() {
    bool tileIsWhite = true;
    //vector<char> letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'];
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
    
    tiles[1][0]->piece = new Knight(1, 0, whitePlayer);
    tiles[6][0]->piece = new Knight(6, 0, whitePlayer);
    tiles[1][7]->piece = new Knight(1, 7, blackPlayer);
    tiles[6][7]->piece = new Knight(6, 7, blackPlayer);
    
    tiles[2][0]->piece = new Bishop(2, 0, whitePlayer);
    tiles[5][0]->piece = new Bishop(5, 0, whitePlayer);
    tiles[2][7]->piece = new Bishop(2, 7, blackPlayer);
    tiles[5][7]->piece = new Bishop(5, 7, blackPlayer);
    
    tiles[3][0]->piece = new Queen(3, 0, whitePlayer);
    tiles[3][7]->piece = new Queen(3, 7, blackPlayer);
    
    tiles[4][0]->piece = new King(4, 0, whitePlayer);
    tiles[4][7]->piece = new King(4, 7, blackPlayer);
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
