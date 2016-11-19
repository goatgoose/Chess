//
//  Piece.hpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef Piece_hpp
#define Piece_hpp

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <Tile.hpp>
#include <iostream>
#include <Vector>

using namespace sf;
using namespace std;

class Piece {
public:
    ~Piece();
    
    void moveTo(int x, int y);
    void setScale(int scale);
    Sprite* getSprite();
    
    virtual vector<Tile> getLegalMoves() = 0;
protected:
    Piece(int x, int y, int scale, string side, string textureName);
    void update();
    
    int x;
    int y;
    int scale;
    string side;
    Texture* texture;
    Sprite* sprite;
};

#endif /* Piece_hpp */
