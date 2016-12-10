//
//  ChessServerAPI.hpp
//  chess
//
//  Created by Sam Clark on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef ChessServerAPI_hpp
#define ChessServerAPI_hpp

#include "restclient-cpp/restclient.h"
#include <iostream>

using namespace std;

class ChessServerAPI {
public:
    static void movePiece(string from, string to, function<void()> success);
};

#endif /* ChessServerAPI_hpp */
