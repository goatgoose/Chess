//
//  Knight.cpp
//  chess
//
//  Created by Sam Clark on 11/21/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Knight.hpp"
#include "ChessBoard.hpp"

Knight::Knight(int x, int y, Player* player): Piece(x, y, player, "knight") {
    
}

vector<Tile*> Knight::getLegalMoves() {
    vector<Coordinate> moves;
    
    moves.push_back(Coordinate(x - 1, y + 2));
    moves.push_back(Coordinate(x + 1, y + 2));
    moves.push_back(Coordinate(x - 1, y - 2));
    moves.push_back(Coordinate(x + 1, y - 2));
    
    moves.push_back(Coordinate(x + 2, y - 1));
    moves.push_back(Coordinate(x + 2, y + 1));
    moves.push_back(Coordinate(x - 2, y - 1));
    moves.push_back(Coordinate(x - 2, y + 1));
    
    vector<Tile*> legalMoves;
    for (int i = 0; i < moves.size(); i++) {
        if (moveIsPossible(moves[i])) {
            legalMoves.push_back(board->getTile(moves[i]));
        }
    }
    
    return legalMoves;
}
