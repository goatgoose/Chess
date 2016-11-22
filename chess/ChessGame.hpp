//
//  ChessGame.hpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef ChessGame_hpp
#define ChessGame_hpp

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include <ChessBoard.hpp>
#include <Clickable.hpp>

using namespace std;
using namespace sf;

class ChessGame {
public:
    ChessGame();
    
    void startGame();
    RenderWindow* window;
    
    Piece* pickedUpPiece;
    Tile* pickedUpPieceTile;
    
    static void addClickable(Clickable* clickable);
    static void removeClickable(Clickable* clickable);
    
private:
    static vector<Clickable*> clickables;
    
    RectangleShape* background;
};

#endif /* ChessGame_hpp */
