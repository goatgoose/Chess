//
//  ChessGame.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessGame.hpp"

ChessGame::ChessGame() {
    this->window = new RenderWindow(VideoMode(1440, 900), "SFML window");
}

void ChessGame::startGame() {
    Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    ChessBoard board(900);
    
    while (window->isOpen()) {
        Event event;
        while (window->pollEvent(event)) {
            
            if (event.type == Event::Closed) {
                window->close();
            } else if (event.type == Event::Resized) {
                // http://stackoverflow.com/questions/27785940/shapes-proportionally-resize-with-window-in-sfml-2-x
                window->setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                
                board.setScale(event.size.height);
            } else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                cout << event.mouseButton.x << ", " << event.mouseButton.y << endl;
                board.tiles[0][1]->piece->moveTo(5, 5);
            }
            
        }
        
        window->clear();
        
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                window->draw(*board.tiles[x][y]->rect);
                if (board.tiles[x][y]->piece != nullptr) {
                    window->draw(*board.tiles[x][y]->piece->getSprite());
                }
            }
        }
        
        window->display();
    }
}
