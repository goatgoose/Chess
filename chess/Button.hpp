//
//  Button.hpp
//  chess
//
//  Created by Sam Clark on 11/22/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <Clickable.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <ChessWindow.hpp>

using namespace sf;

class Button: public Clickable {
public:
    Button(int x, int y, int width, int height, ChessWindow* window, function<void()> clickAction);
    ~Button();
    
    virtual int getX1() override;
    virtual int getY1() override;
    virtual int getX2() override;
    virtual int getY2() override;
    
    virtual void pressEvent() override;
    virtual void releaseEvent() override;
    
    void setLabel(string label);
    void setColor(Color color);
private:
    int x;
    int y;
    int width;
    int height;
    function<void()> clickAction;
    
    RectangleShape* rect;
    Text* text;
};

#endif /* Button_hpp */
