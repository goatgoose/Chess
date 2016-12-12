//
//  Bishop.hpp
//  chess
//
//  Created by Sam Clark
//

#ifndef Bishop_hpp
#define Bishop_hpp

#include <Piece.hpp>

class Bishop: public Piece {
public:
    Bishop(int x, int y, Player* player);
    virtual vector<Tile*> getLegalMoves() override;
};

#endif /* Bishop_hpp */
