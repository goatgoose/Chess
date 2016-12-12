//
//  ChessBoard.hpp
//  chess
//
//  Created by Sam Clark
//

#ifndef ChessBoard_hpp
#define ChessBoard_hpp

#include <iostream>
#include <ChessWindow.hpp>
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

enum GameMode {
    SINGLE_PLAYER,
    MULTI_PLAYER
};

class ChessBoard {
public:
    ChessBoard(int scale, GameMode gameMode, ChessGame* game);
    
    GameMode gameMode;
    ChessGame* game;
    
    Tile* tiles[8][8];
    
    Player* whitePlayer;
    Player* blackPlayer;
    Player* me;
    
    bool waitingForOpponent;
    bool isMyTurn;
    
    void waitForTurn();
    
    void setScale(int scale);
    int getOffset();
    Tile* getTile(Coordinate coordinate);
    
    int scale;
private:
    void waitForOpponent();
    
    void update();
    
    void createTiles();
    void createPieces();
};

#endif /* ChessBoard_hpp */
