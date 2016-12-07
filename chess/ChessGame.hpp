//
//  ChessGame.hpp
//  chess
//
//  Created by Sam Clark on 12/2/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef ChessGame_hpp
#define ChessGame_hpp

#include <ChessWindow.hpp>
#include <ChessBoard.hpp>
#include <Piece.hpp>
#include <Tile.hpp>

class ChessGame: public ChessWindow {
public:
    ChessGame(int scale);
    
    Piece* pickedUpPiece;
    Tile* pickedUpPieceTile;
    
private:
    ChessBoard* board;
    
    virtual void resizeEvent(Event event) override;
};

#endif /* ChessGame_hpp */
