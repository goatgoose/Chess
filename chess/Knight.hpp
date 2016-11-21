//
//  Knight.hpp
//  chess
//
//  Created by Sam Clark on 11/21/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef Knight_hpp
#define Knight_hpp

#include <Piece.hpp>

class Knight: public Piece {
public:
    Knight(int x, int y, Player* player);
    virtual vector<Tile*> getLegalMoves() override;
};

#endif /* Knight_hpp */
