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
#include <iostream>

using namespace sf;
using namespace std;

enum PieceSide {
    WHITE,
    BLACK
};

class Piece {
public:
    ~Piece();
    
    void moveTo(int x, int y);
    void setScale(int scale);
    Sprite* getSprite();
    
    virtual int* getLegalMoves() = 0;
protected:
    Piece(int x, int y, int scale, PieceSide side);
    
    int x;
    int y;
    int scale;
    PieceSide side;
    Texture* texture;
    Sprite* sprite;
};

#endif /* Piece_hpp */
