//
//  Tile.hpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include <Player.hpp>
#include <Clickable.hpp>

using namespace std;
using namespace sf;

class ChessBoard;
class Piece;

class Tile {
public:
    Tile(int x, int y, Side color, ChessBoard* board); // pass player
    ~Tile();
    
    Piece* piece;
    RectangleShape* rect;
    
    void update();
    
    int getX();
    int getY();
    Side getSide();
    
    void clickEvent();
    
private:
    int x;
    int y;
    Side side;
    ChessBoard* board;
    
    Clickable* clickable;
};

#endif /* Tile_hpp */
