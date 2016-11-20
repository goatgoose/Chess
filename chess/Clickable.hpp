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
    Clickable(int x1, int y1, int x2, int y2, string id, function<void()> clickAction);
    Clickable(function<void()> clickAction, string id);
    
    void callback();
    
    int x1;
    int y1;
    int x2;
    int y2;
    
    string getId();
private:
    string id;
    function<void()> clickAction;
};

#endif /* Clickable_hpp */
