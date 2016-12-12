//
//  Button.cpp
//  chess
//
//  Created by Sam Clark 
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
    
    this->label = nullptr;
    
    this->rect = new RectangleShape();
    rect->setFillColor(color);
    update();
    window->addDrawable(rect);
}

void Button::update() {
    this->x = round(this->window->renderWindow->getSize().x * xPercent);
    this->y = round(this->window->renderWindow->getSize().y * yPercent);
    this->width = round(this->window->renderWindow->getSize().x * widthPercent);
    this->height = round(this->window->renderWindow->getSize().y * heightPercent);
    
    rect->setPosition(Vector2f(x, y));
    rect->setSize(Vector2f(width, height));
    
    if (label != nullptr) {
        int labelX = x - ((label->text->getLocalBounds().width - rect->getSize().x) / 2);
        int labelY = y - ((label->text->getLocalBounds().height - rect->getSize().y) / 2);
        label->text->setPosition(Vector2f(labelX, labelY));
    }
}

void Button::setLabel(string content) {
    label = new Label(content, 20, window);
    update();
}

void Button::setColor(Color color) {
    this->color = color;
    rect->setFillColor(color);
}

void Button::pressEvent() {
     rect->setFillColor(Color(color.r-20, color.g-20, color.b-20));
}

void Button::releaseEvent() {
    clickAction();
}

void Button::hoverEvent(){
    rect->setFillColor(Color(color.r+20, color.g+20, color.b+20));
}

void Button::unhoverEvent() {
    rect->setFillColor(color);
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
