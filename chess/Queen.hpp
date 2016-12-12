//
//  Queen.hpp
//  chess
//
//  Created by Sam Clark
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
