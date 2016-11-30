//
//  ChessGame.cpp
//  chess
//
//  Created by Sam Clark on 11/19/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessGame.hpp"

vector<Clickable*> ChessGame::clickables = vector<Clickable*>();
vector<Drawable*> ChessGame::drawables = vector<Drawable*>();

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
    addDrawable(background);
    
    //Button testButton(1000, 100, 50, 20, [&]{cout << "clicky clicky" << endl;});
    
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
                        
                        clickable->releaseEvent();
                        break;
                    }
                }
            } else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                
                for (int i = 0; i < clickables.size(); i++) {
                    Clickable* clickable = clickables[i];
                    if (event.mouseButton.x > clickable->getX1() &&
                        event.mouseButton.x < clickable->getX2() &&
                        event.mouseButton.y > clickable->getY1() &&
                        event.mouseButton.y < clickable->getY2()) {
                        
                        clickable->pressEvent();
                        break;
                    }
                }
            }
        }
        
        window->clear();
        
        for (int i = 0; i < drawables.size(); i++) {
            window->draw(*drawables[i]);
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

void ChessGame::addDrawable(Drawable* drawable) {
    drawables.push_back(drawable);
}

void ChessGame::removeDrawable(Drawable* drawable) {
    vector<Drawable*> newDrawables;
    for (int i = 0; i < drawables.size(); i++) {
        if (drawables[i] != drawable) {
            newDrawables.push_back(drawables[i]);
        }
    }
    drawables = newDrawables;
}













