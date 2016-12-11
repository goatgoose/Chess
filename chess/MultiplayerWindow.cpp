//
//  MultiplayerWindow.cpp
//  chess
//
//  Created by Craig Conway on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "MultiplayerWindow.hpp"

MultiplayerWindow::MultiplayerWindow(): ChessWindow(800, 800, Color(232, 174, 81), false) {
    
    
    joinButton = new Button(0.25, 0.4, 0.5, 0.15, this, [&] {
        this->renderWindow->close();
        ChessGame* chessGame = new ChessGame(720, "test game");
        chessGame->launch();
        
    });
    joinButton->setColor(Color(96, 108, 131));
    
    hostButton = new Button(0.15, 0.8, 0.2, 0.10, this, [&] {cout << "Host Game" << endl;});
    hostButton->setColor(Color(96, 108, 131));
    
    backButton = new Button(0.65, 0.8, 0.2, 0.10, this, [&] {
        this->renderWindow->close();
        MainWindow* mainWindow = new MainWindow();
        mainWindow->launch();
    });
    backButton->setColor(Color(96, 108, 131));
}

void MultiplayerWindow::resizeEvent(Event event) {
    
}
