//
//  Button.cpp
//  chess
//
//  Created by Sam Clark on 11/22/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Button.hpp"

Button::Button(int x, int y, int width, int height, ChessWindow* window, function<void()> clickAction): Clickable(window) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->clickAction = clickAction;
    
    this->color = Color(50, 50, 50);
    
    this->rect = new RectangleShape();
    rect->setSize(Vector2f(width, height));
    rect->setPosition(Vector2f(x, y));
    rect->setFillColor(color);
    window->addDrawable(rect);
    
    Font font;
    font.loadFromFile(resourcePath() + "GlacialIndifference-Regular.otf");
    this->text = new Text("test", font, 14);
    this->text->setPosition(x, y);
    //window->addDrawable(text);
}

void Button::setLabel(string label) {
    this->text->setString(label);
}

void Button::setColor(Color color) {
    this->color = color;
    rect->setFillColor(color);
}

void Button::pressEvent() {
    cout << "press" << endl;
    
}

void Button::releaseEvent() {
    clickAction();
}

void Button::hoverEvent() {
    cout << "hover" << endl;
}

void Button::unhoverEvent() {
    cout << "unhover" << endl;
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
