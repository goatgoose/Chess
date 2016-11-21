//
//  Queen.hpp
//  chess
//
//  Created by Sam Clark on 11/21/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef Queen_hpp
#define Queen_hpp

#include <Piece.hpp>

class Queen: public Piece {
public:
    Queen(int x, int y, Player* player);
    virtual vector<Tile*> getLegalMoves() override;
};

#endif /* Queen_hpp */
