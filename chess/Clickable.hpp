//
//  Clickable.hpp
//  chess
//
//  Created by Sam Clark on 11/20/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef Clickable_hpp
#define Clickable_hpp

#import <iostream>

using namespace std;

class Clickable {
public:
    Clickable();
    ~Clickable();
    
    virtual int getX1() = 0;
    virtual int getY1() = 0;
    virtual int getX2() = 0;
    virtual int getY2() = 0;
    
    virtual void clickEvent() = 0;
};

#endif /* Clickable_hpp */
