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
    
    Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    Sprite sprite(texture);
    
    ChessBoard board;
    board.setScale(900);
    
    while (window->isOpen()) {
        Event event;
        while (window->pollEvent(event)) {
            
            if (event.type == Event::Closed) {
                window->close();
            } else if (event.type == Event::Resized) {
                // http://stackoverflow.com/questions/27785940/shapes-proportionally-resize-with-window-in-sfml-2-x
                window->setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                
                if (event.size.width > event.size.height) {
                    board.setScale(event.size.height);
                } else {
                    board.setScale(event.size.width);
                }
            }
            
        }
        
        window->clear();
        
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                window->draw(*board.tiles[x][y]->getRect());
            }
        }
        
        window->display();
    }
}
