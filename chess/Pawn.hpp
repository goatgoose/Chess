//
//  Pawn.hpp
//  chess
//
//  Created by Sam Clark 
//

#ifndef Pawn_hpp
#define Pawn_hpp

#include <Piece.hpp>

class Pawn: public Piece {
public:
    Pawn(int x, int y, Player* player);
    virtual vector<Tile*> getLegalMoves() override;
    virtual void moveTo(Tile* tile) override;
private:
    bool hasMoved;
};

#endif /* Pawn_hpp */
