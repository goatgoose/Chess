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
#include <Vector>
#include <Tile.hpp>

using namespace sf;
using namespace std;

class ChessBoard;

class Piece {
public:
    ~Piece();
    
    void moveTo(int x, int y);
    void update();
    Sprite* getSprite();
    
    virtual vector<Tile*> getLegalMoves() = 0;
protected:
    Piece(int x, int y, string side, string textureName, ChessBoard* board);
    
    int x;
    int y;
    string side;
    Texture* texture;
    ChessBoard* board;
    Sprite* sprite;
};

#endif /* Piece_hpp */
