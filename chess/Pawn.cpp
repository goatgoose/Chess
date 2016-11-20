//
//  Pawn.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Pawn.hpp"

Pawn::Pawn(int x, int y, int scale, string side): Piece(x, y, scale, side, "pawn") {
    
}

vector<int*> Pawn::getLegalMoves(Piece* pieces) {
    return vector<int*>();
}
