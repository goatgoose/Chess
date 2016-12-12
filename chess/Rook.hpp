//
//  Rook.hpp
//  chess
//
//  Created by Sam Clark
//

#ifndef Rook_hpp
#define Rook_hpp

#include <Piece.hpp>

class Rook: public Piece {
public:
    Rook(int x, int y, Player* player);
    virtual vector<Tile*> getLegalMoves() override;
};

#endif /* Rook_hpp */
