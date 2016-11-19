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
    
    while (window->isOpen()) {
        Event event;
        while (window->pollEvent(event)) {
            
            if (event.type == Event::Closed) {
                window->close();
            }
            
        }
        
        window->clear();
        window->draw(sprite);
        window->display();
    }
}
