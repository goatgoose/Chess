//
//  MultiplayerWindow.cpp
//  chess
//
//  Created by Craig Conway on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "MultiplayerWindow.hpp"

MultiplayerWindow::MultiplayerWindow(): ChessWindow(800, 800, Color(232, 174, 81), false) {
    
    ChessServerAPI::getAvailableServers(this, [&] (vector<string> servers) {
        for (int i = 0; i < servers.size(); i++) {
            string server = servers[i];
            cout << "server: " << server << endl;
            
            Button* serverButton = new Button(0.1, 0.05, 0.8, 0.1, this, [=] {
                this->renderWindow->close();
                ChessGame* chessGame = new ChessGame(720, server, MULTI_PLAYER);
                chessGame->launch();
            });
            serverButton->setColor(Color(96, 108, 131));
            serverButton->setLabel(server);
        }
    });
    
    Button* hostButton = new Button(0.15, 0.8, 0.2, 0.10, this, [&] {
        string serverName = getenv("USER"); // TODO change in windows build
        this->renderWindow->close();
        ChessGame* chessGame = new ChessGame(720, serverName, MULTI_PLAYER);
        chessGame->launch();
    });
    hostButton->setColor(Color(96, 108, 131));
    hostButton->setLabel("Host Game");
    
    Button* backButton = new Button(0.65, 0.8, 0.2, 0.10, this, [&] {
        this->renderWindow->close();
        MainWindow* mainWindow = new MainWindow();
        mainWindow->launch();
    });
    backButton->setColor(Color(96, 108, 131));
    backButton->setLabel("Back");
}
