//
//  Rook.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Rook.hpp"

Rook::Rook(int x, int y, Player* player): Piece(x, y, player, "rook") {
    
}

vector<Tile*> Rook::getLegalMoves() {
    return vector<Tile*>();
}
