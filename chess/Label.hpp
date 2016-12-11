//
//  Label.hpp
//  chess
//
//  Created by Sam Clark on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef Label_hpp
#define Label_hpp

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include <Coordinate.hpp>
#include <ChessWindow.hpp>

using namespace std;

class Label {
public:
    Label(string content, ChessWindow* window);
    void setPosition(Coordinate position);
private:
    string content;
    ChessWindow* window;
    
    Text* text;
};

#endif /* Label_hpp */
