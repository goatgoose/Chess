//
//  Clickable.cpp
//  chess
//
//  Created by Sam Clark on 11/20/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Clickable.hpp"

Clickable::Clickable(int x1, int y1, int x2, int y2, string id, function<void()> clickAction) {
    // http://stackoverflow.com/questions/6458612/c0x-proper-way-to-receive-a-lambda-as-parameter-by-reference
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->id = id;
    this->clickAction = clickAction;
}

Clickable::Clickable(function<void()> clickAction, string id) {
    this->clickAction = clickAction;
    this->id = id;
}

void Clickable::callback() {
    clickAction();
}

string Clickable::getId() {
    return this->id;
}
