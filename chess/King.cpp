//
//  King.cpp
//  chess
//
//  Created by Sam Clark
//

#include "King.hpp"
#include "ChessBoard.hpp"

King::King(int x, int y, Player* player): Piece(x, y, player, "king") {
    
}

vector<Tile*> King::getLegalMoves() {
    vector<Coordinate> moves;
    
    moves.push_back(Coordinate(x - 1, y + 1));
    moves.push_back(Coordinate(x + 0, y + 1));
    moves.push_back(Coordinate(x + 1, y + 1));
    
    moves.push_back(Coordinate(x - 1, y));
    moves.push_back(Coordinate(x + 1, y));
    
    moves.push_back(Coordinate(x - 1, y - 1));
    moves.push_back(Coordinate(x + 0, y - 1));
    moves.push_back(Coordinate(x + 1, y - 1));
    
    // castling
    
    vector<Tile*> legalMoves;
    
    for (int i = 0; i < moves.size(); i++) {
        if(moveIsPossible(moves[i])) {
            legalMoves.push_back(board->getTile(moves[i]));
        }
    }
    
    return legalMoves;
}

