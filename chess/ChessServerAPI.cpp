//
//  ChessServerAPI.cpp
//  chess
//
//  Created by Sam Clark on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessServerAPI.hpp"

void ChessServerAPI::movePiece(Player* lastTurn, string from, string to, function<void()> success) {
    string json = "{lastTurn: " + lastTurn->getSideString() + ", from: " + from + ", to:" + to + "}";
    RestClient::Response response = RestClient::post("http://localhost:4567/movePiece",
                                              "text/json",
                                              json);
    if (response.body == "success") {
        success();
    }
}
