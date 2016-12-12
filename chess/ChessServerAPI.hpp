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
#include <Coordinate.hpp>

class ChessGame;
class ChessBoard;
class ChessWindow;

using namespace std;
using namespace nlohmann;

class ChessServerAPI {
public:
    static void createGame(ChessBoard* board, function<void(bool exists)> success);
    static void deleteGame(ChessBoard* board, function<void()> success);
    static void isWaiting(ChessBoard* board, function<void(bool isWaiting)> success);
    static void movePiece(ChessBoard* board, Coordinate from, Coordinate to, function<void()> success);
    static void getLastTurn(ChessBoard* board, function<void(string lastTurn)> success);
    static void getLastMove(ChessBoard* board, function<void(Coordinate from, Coordinate to)> success);
    static void getAvailableServers(ChessWindow* window, function<void(vector<string> servers)> success);
};

#endif /* ChessServerAPI_hpp */
