//
//  Player.hpp
//  chess
//
//  Created by Craig Conway
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>

using namespace std;

class ChessBoard;

enum Side {
    WHITE,
    BLACK
};

class Player {
public:
    Player(Side side, ChessBoard* board);
    
    ChessBoard* board;
    
    Side getSide();
    string getSideString();
private:
    Side side;
};

#endif /* Player_hpp */
