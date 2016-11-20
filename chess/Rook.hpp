//
//  Rook.hpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef Rook_hpp
#define Rook_hpp

#include <Piece.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include <Vector>

using namespace sf;

class Rook: public Piece {
public:
    Rook(int x, int y, int scale, string side);
    virtual vector<int*> getLegalMoves(Piece* pieces) override;
};

#endif /* Rook_hpp */
