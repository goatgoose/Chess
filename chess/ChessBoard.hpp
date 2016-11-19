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

using namespace std;

class ChessBoard {
public:
    ChessBoard();
    Tile* tiles[8][8];
    
    void setScale(int scale);
    int getOffset();
private:
    void createTiles(bool alreadyExists);
    int scale;
};

#endif /* ChessBoard_hpp */
