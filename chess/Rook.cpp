//
//  Rook.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Rook.hpp"
#include "ChessBoard.hpp"

Rook::Rook(int x, int y, Player* player): Piece(x, y, player, "rook") {
    
}

vector<Tile*> Rook::getLegalMoves() {
    vector<Tile*> legalMoves;
    
    // moves to the right
    for (int i = x + 1; i < 8; i++) {
        Tile* tile = board->getTile(Coordinate(i, y));
        if (moveIsPossible(tile)) {
            legalMoves.push_back(tile);
        }
        if (tile->piece != nullptr) { // if we hit a piece don't add moves past it
            break;
        }
    }
    
    // moves to the left
    for (int i = x - 1; i >= 0; i--) {
        Tile* tile = board->getTile(Coordinate(i, y));
        if (moveIsPossible(tile)) {
            legalMoves.push_back(tile);
        }
        if (tile->piece != nullptr) {
            break;
        }
    }
    
    // moves above
    for (int i = y - 1; i >= 0; i--) {
        Tile* tile = board->getTile(Coordinate(x, i));
        if (moveIsPossible(tile)) {
            legalMoves.push_back(tile);
        }
        if (tile->piece != nullptr) {
            break;
        }
    }
    
    // moves below
    for (int i = y + 1; i < 8; i++) {
        Tile* tile = board->getTile(Coordinate(x, i));
        if (moveIsPossible(tile)) {
            legalMoves.push_back(tile);
        }
        if (tile->piece != nullptr) {
            break;
        }
    }
    
    return legalMoves;
}
