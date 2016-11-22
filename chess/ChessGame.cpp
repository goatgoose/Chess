//
//  ChessGame.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessGame.hpp"

vector<Clickable*> ChessGame::clickables = vector<Clickable*>();

ChessGame::ChessGame() {
    this->window = new RenderWindow(VideoMode(1440, 900), "SFML window");
    this->pickedUpPiece = nullptr;
    this->pickedUpPieceTile = nullptr;
}

void ChessGame::startGame() {
    Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    background = new RectangleShape();
    background->setSize(Vector2f(1440, 900));
    background->setPosition(Vector2f(0, 0));
    background->setFillColor(Color(38, 50, 71));
    
    ChessBoard board(900, this);
    
    while (window->isOpen()) {
        Event event;
        while (window->pollEvent(event)) {
            
            if (event.type == Event::Closed) {
                window->close();
                
            } else if (event.type == Event::Resized) {
                // http://stackoverflow.com/questions/27785940/shapes-proportionally-resize-with-window-in-sfml-2-x
                window->setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                
                board.setScale(event.size.height);
                background->setSize(Vector2f(event.size.width, event.size.height));
                
            } else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                //cout << event.mouseButton.x << ", " << event.mouseButton.y << endl;
                
                for (int i = 0; i < clickables.size(); i++) {
                    Clickable* clickable = clickables[i];
                    if (event.mouseButton.x > clickable->getX1() &&
                        event.mouseButton.x < clickable->getX2() &&
                        event.mouseButton.y > clickable->getY1() &&
                        event.mouseButton.y < clickable->getY2()) {
                        
                        clickable->clickEvent();
                        break;
                    }
                }
            }
            
        }
        
        window->clear();
        
        window->draw(*background);
        
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

void ChessGame::addClickable(Clickable* clickable) {
    clickables.push_back(clickable);
}

void ChessGame::removeClickable(Clickable* clickable) {
    vector<Clickable*> newClickables;
    for (int i = 0; i < clickables.size(); i++) {
        if (clickables[i] != clickable) {
            newClickables.push_back(clickables[i]);
        }
    }
    clickables = newClickables;
}














