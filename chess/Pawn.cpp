//
//  Pawn.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Pawn.hpp"

Pawn::Pawn(int x, int y, string side, ChessBoard* board): Piece(x, y, side, "pawn", board) {
    
}

vector<Tile*> Pawn::getLegalMoves() {
    return vector<Tile*>();
}
