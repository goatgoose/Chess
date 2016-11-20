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
    
    void addClickable(Clickable* clickable);
    void removeClickable(string id);
    
private:
    vector<Clickable*> clickables;
};

#endif /* ChessGame_hpp */
