//
//  Tile.hpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <Tile.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>

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
    
    void setScale(int scale);
    
    int getX();
    int getY();
    TileColor getColor();
    RectangleShape* getRect();
    
private:
    void update();
    
    int x;
    int y;
    int scale;
    TileColor color;
    RectangleShape* rect;
};

#endif /* Tile_hpp */
