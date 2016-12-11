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
#include <MainWindow.hpp>
#include <ChessBoard.hpp>
#include <Piece.hpp>
#include <Tile.hpp>
#include <Button.hpp>

class ChessGame: public ChessWindow {
public:
    ChessGame(int scale, string name, GameMode gameMode);
    
    Piece* pickedUpPiece;
    Tile* pickedUpPieceTile;
    
    string getName();
    
private:
    string name;
    
    ChessBoard* board;
    
    virtual void resizeEvent(Event event) override;
    
    Button* drawButton;
    Button* secedeButton;
};

#endif /* ChessGame_hpp */
