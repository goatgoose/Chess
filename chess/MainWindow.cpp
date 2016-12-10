//
//  MainWindow.cpp
//  chess
//
//  Created by Craig Conway on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "MainWindow.hpp"

MainWindow::MainWindow(): ChessWindow(240, 400, Color(232, 174, 81)) {
    
    
    localButton = new Button(0.5, 0.4, 0.4, 0.275, this, [&] {
        this->renderWindow->close();
        ChessGame* chessGame = new ChessGame(720, "test name");
        chessGame->launch();
        
    });
    localButton->setColor(Color(96, 108, 131));
    
    multiplayerButton = new Button(0.5, 0.6, 0.4, 0.275, this, [&] {cout << "MultiPlayer" << endl;});
    multiplayerButton->setColor(Color(96, 108, 131));

    
};

void MainWindow::resizeEvent(Event event) {}
