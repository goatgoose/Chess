//
//  Rook.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Rook.hpp"

Rook::Rook(int x, int y, int scale, string side): Piece(x, y, scale, side, "rook") {
    
}

vector<int*> Rook::getLegalMoves(Piece* pieces) {
    return vector<int*>();
}
