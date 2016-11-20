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
#include <Player.hpp>
#include <Coordinate.hpp>

using namespace sf;
using namespace std;

class Piece {
public:
    ~Piece();
    
    virtual void moveTo(Tile* tile);
    void update();
    virtual vector<Tile*> getLegalMoves() = 0;
    
    bool moveIsPossible(Coordinate move);
    
    Sprite* getSprite();
    Side getSide();
protected:
    Piece(int x, int y, Player* player, string textureName);
    
    int x;
    int y;
    Player* player;
    
    ChessBoard* board;
    Side side;
    
    Texture* texture;
    Sprite* sprite;
};

#endif /* Piece_hpp */
