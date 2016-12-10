//
//  Button.cpp
//  chess
//
//  Created by Sam Clark on 11/22/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Button.hpp"

Button::Button(float xPercent, float yPercent, float widthPercent, float heightPercent, ChessWindow* window, function<void()> clickAction): Clickable(window) {
    this->xPercent = xPercent;
    this->yPercent = yPercent;
    this->widthPercent = widthPercent;
    this->heightPercent = heightPercent;
    this->window = window;
    this->clickAction = clickAction;
    
    this->color = Color(50, 50, 50);
    
    this->rect = new RectangleShape();
    rect->setFillColor(color);
    update();
    window->addDrawable(rect);
    
    Font font;
    if (font.loadFromFile(resourcePath() + "GlacialIndifference-Regular.otf")) {
        cout << "test" << endl;
        this->text = new Text();
        text->setFont(font);
        text->setString("Hello world");
        text->setCharacterSize(20);
        text->setFillColor(Color::Red);
        window->addDrawable(text);
    }
}

void Button::update() {
    this->x = round(this->window->renderWindow->getSize().x * xPercent);
    this->y = round(this->window->renderWindow->getSize().y * yPercent);
    this->width = round(this->window->renderWindow->getSize().x * widthPercent);
    this->height = round(this->window->renderWindow->getSize().y * heightPercent);
    
    cout << "x: " << x << ", width: " << width << endl;
    rect->setPosition(Vector2f(x, y));
    rect->setSize(Vector2f(width, height));
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
