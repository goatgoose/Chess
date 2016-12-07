//
//  ChessWindow.cpp
//  chess
//
//  Created by Sam Clark on 12/2/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessWindow.hpp"

ChessWindow::ChessWindow(int x, int y, Color backgroundColor) {
    this->renderWindow = new RenderWindow(VideoMode(1440, 900), "SFML window");
    
    this->clickables = vector<Clickable*>();
    this->drawables = vector<Drawable*>();
    
    background = new RectangleShape();
    background->setSize(Vector2f(1440, 900));
    background->setPosition(Vector2f(0, 0));
    background->setFillColor(backgroundColor);
    addDrawable(background);
}

void ChessWindow::launch() {
    while (renderWindow->isOpen()) {
        Event event;
        while (renderWindow->pollEvent(event)) {
            
            if (event.type == Event::Closed) {
                renderWindow->close();
                
            } else if (event.type == Event::Resized) {
                // http://stackoverflow.com/questions/27785940/shapes-proportionally-resize-with-window-in-sfml-2-x
                renderWindow->setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                
                background->setSize(Vector2f(event.size.width, event.size.height));
                this->resizeEvent(event);
                
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
        
        renderWindow->clear();
        
        for (int i = 0; i < drawables.size(); i++) {
            renderWindow->draw(*drawables[i]);
        }
        
        renderWindow->display();
    }
}

void ChessWindow::addClickable(Clickable* clickable) {
    clickables.push_back(clickable);
}

void ChessWindow::removeClickable(Clickable* clickable) {
    vector<Clickable*> newClickables;
    for (int i = 0; i < clickables.size(); i++) {
        if (clickables[i] != clickable) {
            newClickables.push_back(clickables[i]);
        }
    }
    clickables = newClickables;
}

void ChessWindow::addDrawable(Drawable* drawable) {
    drawables.push_back(drawable);
}

void ChessWindow::removeDrawable(Drawable* drawable) {
    vector<Drawable*> newDrawables;
    for (int i = 0; i < drawables.size(); i++) {
        if (drawables[i] != drawable) {
            newDrawables.push_back(drawables[i]);
        }
    }
    drawables = newDrawables;
}
