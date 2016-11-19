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
    Tile(int x, int y, TileColor color);
    
    int getX();
    int getY();
    TileColor getColor();
    RectangleShape getRect();
    
private:
    int x;
    int y;
    TileColor color;
    RectangleShape rect;
};

#endif /* Tile_hpp */
