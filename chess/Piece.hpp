//
//  Piece.hpp
//  chess
//
//  Created by Sam Clark and Craig Conway
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
#include <ChessServerAPI.hpp>

using namespace sf;
using namespace std;

class Piece {
public:
    virtual ~Piece();
    
    virtual void moveTo(Tile* tile);
    void update();
    virtual vector<Tile*> getLegalMoves() = 0;
    
    virtual bool moveIsPossible(Coordinate move);
    virtual bool moveIsPossible(Tile* tile);
    
    Player* player;
    
    Sprite* getSprite();
    Side getSide();
protected:
    Piece(int x, int y, Player* player, string textureName);
    
    int x;
    int y;
    
    ChessBoard* board;
    Side side;
    
    Texture* texture;
    Sprite* sprite;
};

#endif /* Piece_hpp */
