//
//  Clickable.hpp
//  chess
//
//  Created by Sam Clark on 11/20/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef Clickable_hpp
#define Clickable_hpp

class ChessWindow;

class Clickable {
public:
    Clickable(ChessWindow* window);
    ~Clickable();
    
    bool isInBounds(int x, int y);
    
    virtual int getX1() = 0;
    virtual int getY1() = 0;
    virtual int getX2() = 0;
    virtual int getY2() = 0;
    
    virtual void pressEvent();
    virtual void releaseEvent();
    
    virtual void hoverEvent();
    virtual void unhoverEvent();
    
private:
    ChessWindow* window;
};

#endif /* Clickable_hpp */
