//
//  Bishop.cpp
//  chess
//
//  Created by Sam Clark on 11/21/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Bishop.hpp"
#include "ChessBoard.hpp"

Bishop::Bishop(int x, int y, Player* player): Piece(x, y, player, "bishop") {
    
}

vector<Tile*> Bishop::getLegalMoves() {
    vector<Tile*> legalMoves;
    
    Tile* tile;
    
    // diagonal bottom right
    tile = board->getTile(Coordinate(x + 1, y + 1));
    while (tile != nullptr) {
        if (moveIsPossible(tile)) {
            legalMoves.push_back(tile);
        }
        if (tile->piece != nullptr) {
            break;
        }
        tile = board->getTile(Coordinate(tile->getX() + 1, tile->getY() + 1));
    }
    
    // diagonal top right
    tile = board->getTile(Coordinate(x + 1, y - 1));
    while (tile != nullptr) {
        if (moveIsPossible(tile)) {
            legalMoves.push_back(tile);
        }
        if (tile->piece != nullptr) {
            break;
        }
        tile = board->getTile(Coordinate(tile->getX() + 1, tile->getY() - 1));
    }
    
    // diagonal bottom left
    tile = board->getTile(Coordinate(x - 1, y + 1));
    while (tile != nullptr) {
        if (moveIsPossible(tile)) {
            legalMoves.push_back(tile);
        }
        if (tile->piece != nullptr) {
            break;
        }
        tile = board->getTile(Coordinate(tile->getX() - 1, tile->getY() + 1));
    }
    
    // diagonal top left
    tile = board->getTile(Coordinate(x - 1, y - 1));
    while (tile != nullptr) {
        if (moveIsPossible(tile)) {
            legalMoves.push_back(tile);
        }
        if (tile->piece != nullptr) {
            break;
        }
        tile = board->getTile(Coordinate(tile->getX() - 1, tile->getY() - 1));
    }
    
    return legalMoves;
}

