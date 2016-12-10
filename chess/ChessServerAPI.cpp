//
//  ChessServerAPI.cpp
//  chess
//
//  Created by Sam Clark on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessServerAPI.hpp"
#include "ChessGame.hpp"
#include "ChessBoard.hpp"

void ChessServerAPI::movePiece(ChessBoard* board, string from, string to, function<void()> success) {
    string json =   "{game: " + board->game->getName() +
                    "lastTurn: " + board->me->getSideString() +
                    ", from: " + from +
                    ", to:" + to + "}";
    RestClient::Response response = RestClient::post("http://localhost:4567/movePiece",
                                              "text/json",
                                              json);
    if (response.body == "success") {
        success();
    }
}

vector<string> ChessServerAPI::getAvalibleServers() {
    vector<string> tempServerNames;
    tempServerNames.push_back("Test server 1");
    tempServerNames.push_back("Test server 2");
    tempServerNames.push_back("Test server 3");
}
