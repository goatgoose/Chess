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

class Tile: public Clickable {
public:
    Tile(int x, int y, Side color, ChessBoard* board); // pass player?
    ~Tile();
    
    Piece* piece;
    RectangleShape* rect;
    
    void update();
    
    void highlight();
    void resetHighlight();
    
    int getX();
    int getY();
    Side getSide();
    
    virtual void clickEvent() override;
    
    virtual int getX1() override;
    virtual int getY1() override;
    virtual int getX2() override;
    virtual int getY2() override;
    
private:
    int x;
    int y;
    int scale;
    Side side;
    ChessBoard* board;
    
    void setColor();
};

#endif /* Tile_hpp */
