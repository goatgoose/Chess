//
//  Knight.hpp
//  chess
//
//  Created by Sam Clark
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
