//
//  Board.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessBoard.hpp"
#include "ChessGame.hpp"

ChessBoard::ChessBoard(int scale, GameMode gameMode, ChessGame* game) {
    this->scale = scale;
    this->gameMode = gameMode;
    this->game = game;
    
    this->whitePlayer = new Player(WHITE, this);
    this->blackPlayer = new Player(BLACK, this);
    
    createTiles();
    createPieces();
    
    if (gameMode == MULTI_PLAYER) {
        ChessServerAPI::createGame(this, [&] (bool exists) {
            if (exists) {
                me = blackPlayer;
                this->isMyTurn = false;
                waitForTurn();
            } else {
                me = whitePlayer;
                this->isMyTurn = true;
                this->waitingForOpponent = true;
                waitForOpponent();
            }
        });
    } else {
        me = whitePlayer;
        this->isMyTurn = true;
        this->waitingForOpponent = false;
    }
}

void ChessBoard::waitForOpponent() {
    this->game->notificationLabel->text->setString(sf::String("Waiting for opponent..."));
    game->addTimer(new Timer(5, [&] {
        ChessServerAPI::isWaiting(this, [&] (bool isWaiting) {
            if (isWaiting) {
                waitForOpponent();
            } else {
                waitingForOpponent = false;
                game->notificationLabel->text->setString(sf::String(""));
            }
        });
    }));
}

void ChessBoard::waitForTurn() {
    game->addTimer(new Timer(5, [&] {
        ChessServerAPI::getLastTurn(this, [&] (string lastTurn) {
            if (lastTurn == me->getSideString()) {
                waitForTurn();
            } else {
                ChessServerAPI::getLastMove(this, [&] (Coordinate from, Coordinate to) {
                    Piece* piece = tiles[from.getX()][from.getY()]->piece;
                    piece->moveTo(tiles[to.getX()][to.getY()]);
                    isMyTurn = true;
                });
            }
        });
    }));
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

Piece* ChessBoard::getPiece(string name, Side side) {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            Tile* tile = tiles[x][y];
            if (tile->piece != nullptr) {
                Piece* piece = tile->piece;
                if (piece->textureName == name && piece->getSide() == side) {
                    return piece;
                }
            }
        }
    }
}




