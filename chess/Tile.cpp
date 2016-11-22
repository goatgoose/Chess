//
//  Tile.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Tile.hpp"
#include "ChessBoard.hpp"
#include "ChessGame.hpp"

Tile::Tile(int x, int y, Side side, ChessBoard* board) {
    this->x = x;
    this->y = y;
    this->board = board;
    this->side = side;
    this->scale = board->getOffset();
    
    rect = new RectangleShape();
    setColor();
    update();
}

void Tile::update() {
    rect->setSize(Vector2f(scale, scale));
    rect->setPosition(Vector2f(scale * x, scale * y));
}

void Tile::clickEvent() {
    cout << "click for: " << x << ", " << y << endl;
    if (board->isMyTurn) {
        if (board->game->pickedUpPiece == nullptr) { // choose a piece to move mode
            if (piece != nullptr) {
                if (piece->player == board->me) {
                    board->game->pickedUpPiece = piece;
                    board->game->pickedUpPieceTile = this;
                    
                    vector<Tile*> legalMoves = piece->getLegalMoves();
                    for (int i = 0; i < legalMoves.size(); i++) {
                        Tile* legalMove = legalMoves[i];
                        legalMove->highlight();
                    }
                    board->game->pickedUpPieceTile->highlight();
                }
            }
        } else { // move a piece mode
            bool isALegalMove = false;
            vector<Tile*> legalMoves = board->game->pickedUpPiece->getLegalMoves();
            for (int i = 0; i < legalMoves.size(); i++) {
                Tile* legalMove = legalMoves[i];
                if (legalMove->getX() == this->x && legalMove->getY() == this->y) {
                    isALegalMove = true;
                }
                legalMove->resetHighlight();
            }
            board->game->pickedUpPieceTile->resetHighlight();
            
            if (isALegalMove) {
                board->game->pickedUpPiece->moveTo(this);
                board->isMyTurn = false;
                // send move to server
                
                // temp while no server
                board->isMyTurn = true;
                if (board->me == board->blackPlayer) {
                    board->me = board->whitePlayer;
                } else {
                    board->me = board->blackPlayer;
                }
            }
            
            board->game->pickedUpPiece = nullptr;
            board->game->pickedUpPieceTile = nullptr;
            
        }
    }
}

void Tile::setColor() {
    // color theme:
    // https://color.adobe.com/1944mustang-color-theme-4817/
    
    if (side == WHITE) {
        rect->setFillColor(Color(126, 138, 161));
    } else {
        rect->setFillColor(Color(38, 50, 71));
    }
}

void Tile::highlight() {
    if (side == WHITE) {
        rect->setFillColor(Color(188, 144, 103));
    } else {
        rect->setFillColor(Color(145, 101, 60));
    }
}

void Tile::resetHighlight() {
    setColor();
}

int Tile::getX1() {
    return scale * x;
}

int Tile::getY1() {
    return scale * y;
}

int Tile::getX2() {
    return getX1() + scale;
}

int Tile::getY2() {
    return getY1() + scale;
}

int Tile::getX() {
    return this->x;
}

int Tile::getY() {
    return this->y;
}

Side Tile::getSide() {
    return this->side;
}

Tile::~Tile() {
    delete this->rect;
}

