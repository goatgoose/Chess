//
//  King.hpp
//  chess
//
//  Created by Sam Clark
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
