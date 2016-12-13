//
//  Tile.cpp
//  chess
//
//  Created by Craig Conway
//

#include "Tile.hpp"
#include "ChessBoard.hpp"
#include "ChessGame.hpp"

Tile::Tile(int x, int y, Side side, ChessBoard* board): Clickable(board->game) {
    this->x = x;
    this->y = y;
    this->board = board;
    this->side = side;
    
    rect = new RectangleShape();
    setColor();
    this->board->game->addDrawable(rect);
    update();
}

void Tile::update() {
    int scale = board->getOffset();
    rect->setSize(Vector2f(scale, scale));
    rect->setPosition(Vector2f(scale * x, scale * y));
}

void Tile::releaseEvent() {
    if (board->isMyTurn && !board->waitingForOpponent) {
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
                
                if (board->gameMode == SINGLE_PLAYER) {
                    board->isMyTurn = true;
                    if (board->me == board->blackPlayer) {
                        board->me = board->whitePlayer;
                    } else {
                        board->me = board->blackPlayer;
                    }
                } else if (board->gameMode == MULTI_PLAYER) {
                    board->isMyTurn = false;
                    Coordinate from(board->game->pickedUpPieceTile->getX(), board->game->pickedUpPieceTile->getY());
                    Coordinate to(x, y);
                    ChessServerAPI::movePiece(board, from, to, [&] {
                        board->waitForTurn();
                    });
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

Coordinate Tile::getPosition() {
    return Coordinate(x, y);
}

int Tile::getX1() {
    
    return board->getOffset() * x;
}

int Tile::getY1() {
    return board->getOffset() * y;
}

int Tile::getX2() {
    return getX1() + board->getOffset();
}

int Tile::getY2() {
    return getY1() + board->getOffset();
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

