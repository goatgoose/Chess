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

string url = "http://localhost:4567/";

void ChessServerAPI::movePiece(ChessBoard* board, string from, string to, function<void()> success) {
    json request;
    request["game"] = board->game->getName();
    request["player"] = board->me->getSideString();
    request["from"] = from;
    request["to"] = to;
    
    RestClient::Response response = RestClient::post(url + "movePiece", "text/json", request.dump());
    if (response.body == "success") {
        success();
    }
}

string ChessServerAPI::getLastTurn(ChessBoard* board, function<void(string lastTurn)> success) {
    json request;
    request["game"] = board->game->getName();
    
    RestClient::Response response = RestClient::post(url + "getLastTurn", "text/json", request.dump());
    if (response.body == "success") {
        json responseObj = json::parse(response.body);
        success(responseObj["game"]);
    }
}

vector<string> ChessServerAPI::getAvalibleServers() {
    vector<string> tempServerNames;
    tempServerNames.push_back("Test server 1");
    tempServerNames.push_back("Test server 2");
    tempServerNames.push_back("Test server 3");
}
