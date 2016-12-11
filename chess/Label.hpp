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
    Label(string content, int size, ChessWindow* window);
    
    Text* text;
private:
    string content;
    int size;
    ChessWindow* window;
};

#endif /* Label_hpp */
