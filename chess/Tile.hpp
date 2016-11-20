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

enum TileColor {
    WHITE,
    BLACK
};

class Tile {
public:
    Tile(int x, int y, int scale, TileColor color);
    ~Tile();
    
    Piece* piece;
    
    RectangleShape* rect;
    
    void setScale(int scale);
    
    int getX();
    int getY();
    TileColor getColor();
    
private:
    void update();
    
    int x;
    int y;
    int scale;
    TileColor color;
};

#endif /* Tile_hpp */
