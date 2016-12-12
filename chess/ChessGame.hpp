//
//  ChessGame.hpp
//  chess
//
//  Created by Sam Clark and Craig Conway
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
    
    Label* notificationLabel;
    
    string getName();
    
    ~ChessGame();
private:
    int scale;
    string name;
    GameMode gameMode;
    
    ChessBoard* board;
    
    virtual void resizeEvent(Event event) override;
    virtual void closeEvent(Event event) override;
    
    void update();
    
    Button* drawButton;
    Button* secedeButton;
};

#endif /* ChessGame_hpp */
