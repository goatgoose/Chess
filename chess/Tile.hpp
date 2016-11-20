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
#include <Piece.hpp>

using namespace std;
using namespace sf;

class ChessBoard;

enum TileColor {
    WHITE,
    BLACK
};

class Tile {
public:
    Tile(int x, int y, TileColor color, ChessBoard* board);
    ~Tile();
    
    Piece* piece;
    RectangleShape* rect;
    
    void update();
    
    int getX();
    int getY();
    TileColor getColor();
    
private:
    
    int x;
    int y;
    TileColor color;
    ChessBoard* board;
};

#endif /* Tile_hpp */
