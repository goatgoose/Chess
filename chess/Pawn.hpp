//
//  Pawn.hpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef Pawn_hpp
#define Pawn_hpp

#include <Piece.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include <Vector>

using namespace sf;

class Pawn: public Piece {
public:
    Pawn(int x, int y, int scale, string side);
    virtual vector<Tile> getLegalMoves() override;
};

#endif /* Pawn_hpp */
