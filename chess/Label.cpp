//
//  Label.cpp
//  chess
//
//  Created by Sam Clark on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Label.hpp"

Label::Label(string content, ChessWindow* window) {
    this->content = content;
    this->window = window;
    
    sf::String label("test");
    this->text = new Text(label, window->font, 20);
    this->text->setFillColor(Color::Red);
    this->text->setPosition(20, 40);
    window->addDrawable(text);
}

void Label::setPosition(Coordinate position) {
    
}
