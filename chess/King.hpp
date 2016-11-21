//
//  King.hpp
//  chess
//
//  Created by Sam Clark on 11/21/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef King_hpp
#define King_hpp

#include <Piece.hpp>

class King: public Piece {
public:
    King(int x, int y, Player* player);
    virtual vector<Tile*> getLegalMoves() override;
};

#endif /* King_hpp */
