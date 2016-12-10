//
//  ChessServerAPI.cpp
//  chess
//
//  Created by Sam Clark on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "ChessServerAPI.hpp"

void ChessServerAPI::movePiece(string from, string to, function<void()> success) {
    string json = "{from: " + from + ", to:" + to + "}";
    RestClient::Response response = RestClient::post("http://localhost:4567/movePiece",
                                              "text/json",
                                              json);
    if (response.body == "success") {
        success();
    }
}
