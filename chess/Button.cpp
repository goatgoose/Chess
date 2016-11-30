//
//  Button.cpp
//  chess
//
//  Created by Sam Clark on 11/22/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Button.hpp"
#include "ChessGame.hpp"

Button::Button(int x, int y, int width, int height, function<void()> clickAction) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->clickAction = clickAction;
    
    this->rect = new RectangleShape();
    rect->setPosition(Vector2f(x, y));
    rect->setSize(Vector2f(width, height));
    rect->setFillColor(Color(253, 151, 39));
    ChessGame::addDrawable(rect);
    
    Font font;
    font.loadFromFile(resourcePath() + "GlacialIndifference-Regular.otf");
    this->text = new Text("test", font, 14);
    this->text->setPosition(x, y);
    ChessGame::addDrawable(text);
}

void Button::setLabel(string label) {
    this->text->setString(label);
}

void Button::setColor(Color color) {
    rect->setFillColor(color);
}

void Button::pressEvent() {
    
}

void Button::releaseEvent() {
    clickAction();
}

int Button::getX1() {
    return x;
}

int Button::getY1() {
    return y;
}

int Button::getX2() {
    return x + width;
}

int Button::getY2() {
    return y + height;
}

Button::~Button() {
    delete rect;
}
