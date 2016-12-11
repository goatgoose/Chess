//
//  MainWindow.cpp
//  chess
//
//  Created by Craig Conway on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "MainWindow.hpp"

MainWindow::MainWindow(): ChessWindow(400, 700, Color(232, 174, 81), false) {
    
    
    localButton = new Button(0.25, 0.4, 0.5, 0.15, this, [&] {
        this->renderWindow->close();
        ChessGame* chessGame = new ChessGame(720, "test name");
        chessGame->launch();
        
    });
    localButton->setColor(Color(96, 108, 131));
    localButton->setLabel("Local Game");
    
    multiplayerButton = new Button(0.25, 0.6, 0.5, 0.15, this, [&] {
        this->renderWindow->close();
        MultiplayerWindow* multiplayerWindow = new MultiplayerWindow();
        multiplayerWindow->launch();
    
    });
    multiplayerButton->setColor(Color(96, 108, 131));
    multiplayerButton->setLabel("Multiplayer Game");

};

void MainWindow::resizeEvent(Event event) {}
