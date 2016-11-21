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
#include <Player.hpp>
#include <Tile.hpp>
#include <Pawn.hpp>
#include <Rook.hpp>
#include <Knight.hpp>
#include <Bishop.hpp>
#include <Queen.hpp>
#include <King.hpp>

using namespace std;
using namespace sf;

class ChessGame;

class ChessBoard {
public:
    ChessBoard(int scale, ChessGame* game);
    
    ChessGame* game;
    
    Tile* tiles[8][8];
    
    Player* whitePlayer;
    Player* blackPlayer;
    Player* me;
    Player* other;
    
    bool isMyTurn;
    
    void setScale(int scale);
    int getOffset();
    Tile* getTile(Coordinate coordinate);
private:
    void update();
    
    void createTiles();
    void createPieces();
    int scale;
};

#endif /* ChessBoard_hpp */
