//
//  Queen.cpp
//  chess
//
//  Created by Sam Clark on 11/21/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Queen.hpp"
#include "ChessBoard.hpp"

Queen::Queen(int x, int y, Player* player): Piece(x, y, player, "queen") {
    cout << "test" << endl;
}

vector<Tile*> Queen::getLegalMoves() {
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
