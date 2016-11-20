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
#include <Pawn.hpp>
#include <Tile.hpp>
#include <Player.hpp>

using namespace std;

class ChessBoard {
public:
    ChessBoard(int scale);
    Tile* tiles[8][8];
    
    Player* whitePlayer;
    Player* blackPlayer;
    
    void setScale(int scale);
    int getOffset();
private:
    void update();
    
    void createTiles();
    void createPieces();
    int scale;
};

#endif /* ChessBoard_hpp */
