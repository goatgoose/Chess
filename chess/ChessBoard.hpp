//
//  ChessBoard.hpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef ChessBoard_hpp
#define ChessBoard_hpp

#include <iostream>
#include <Tile.hpp>
#include <Piece.hpp>
#include <Pawn.hpp>

using namespace std;

class ChessBoard {
public:
    ChessBoard(int scale);
    Tile* tiles[8][8];
    Piece* pieces[8][8];
    
    void setScale(int scale);
    int getOffset();
private:
    void update();
    
    void createTiles();
    void createPieces();
    int scale;
};

#endif /* ChessBoard_hpp */
