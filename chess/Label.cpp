//
//  Label.cpp
//  chess
//
//  Created by Sam Clark on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Label.hpp"

Label::Label(string content, int size, ChessWindow* window) {
    this->content = content;
    this->size = size;
    this->window = window;
    
    sf::String label(content);
    this->text = new Text(label, window->font, size);
    this->text->setFillColor(Color::Black);
    window->addDrawable(text);
}
