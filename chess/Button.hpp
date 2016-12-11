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
#include <math.h>
#include <Label.hpp>

using namespace sf;

class Button: public Clickable {
public:
    Button(float xPercent, float yPercent, float widthPercent, float heightPercent, ChessWindow* window, function<void()> clickAction);
    ~Button();
    
    virtual int getX1() override;
    virtual int getY1() override;
    virtual int getX2() override;
    virtual int getY2() override;
    
    virtual void pressEvent() override;
    virtual void releaseEvent() override;
    virtual void hoverEvent() override;
    virtual void unhoverEvent() override;
    
    void setLabel(string content);
    void setColor(Color color);
    
    void update();
private:
    float xPercent;
    float yPercent;
    int x;
    int y;
    int width;
    int height; 
    float widthPercent;
    float heightPercent;
    ChessWindow* window;
    function<void()> clickAction;
    
    Color color;
    
    Label* label;
    
    RectangleShape* rect;
    Text* text;
};

#endif /* Button_hpp */
