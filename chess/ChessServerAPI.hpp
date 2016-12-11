//
//  ChessServerAPI.hpp
//  chess
//
//  Created by Sam Clark on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef ChessServerAPI_hpp
#define ChessServerAPI_hpp

#include "json.hpp"
#include "restclient-cpp/restclient.h"
#include <iostream>
#include <vector>

class ChessGame;
class ChessBoard;

using namespace std;
using namespace nlohmann;

class ChessServerAPI {
public:
    static void movePiece(ChessBoard* board, string from, string to, function<void()> success);
    static string getLastTurn(ChessBoard* board, function<void(string lastTurn)> success);
    static vector<string> getAvalibleServers();
};

#endif /* ChessServerAPI_hpp */
