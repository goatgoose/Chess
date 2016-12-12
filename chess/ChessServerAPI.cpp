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

void ChessServerAPI::createGame(ChessBoard* board, function<void(bool exists)> success) {
    json request;
    request["game"] = board->game->getName();
    
    RestClient::Response response = RestClient::post(url + "createGame", "text/json", request.dump());
    if (response.code == 200) {
        if (response.body == "success") {
            success(false);
        } else {
            success(true);
        }
    }
}

void ChessServerAPI::deleteGame(ChessBoard* board, function<void()> success) {
    cout << "delete" << endl;
    json request;
    request["game"] = board->game->getName();
    
    RestClient::Response response = RestClient::post(url + "deleteGame", "text/json", request.dump());
    if (response.code == 200) {
        success();
    }
}

void ChessServerAPI::movePiece(ChessBoard* board, Coordinate from, Coordinate to, function<void()> success) {
    json request;
    request["game"] = board->game->getName();
    request["player"] = board->me->getSideString();
    request["from"] = {
        {"x", from.getX()},
        {"y", from.getY()}
    };
    request["to"] = {
        {"x", to.getX()},
        {"y", to.getY()}
    };
    
    RestClient::Response response = RestClient::post(url + "movePiece", "text/json", request.dump());
    if (response.code == 200) {
        success();
    }
}

void ChessServerAPI::getLastTurn(ChessBoard* board, function<void(string lastTurn)> success) {
    json request;
    request["game"] = board->game->getName();
    
    RestClient::Response response = RestClient::post(url + "getLastTurn", "text/json", request.dump());
    if (response.code == 200) {
        json responseObj = json::parse(response.body);
        success(responseObj["turn"]);
    }
}

void ChessServerAPI::getLastMove(ChessBoard* board, function<void(Coordinate from, Coordinate to)> success) {
    json request;
    request["game"] = board->game->getName();
    
    RestClient::Response response = RestClient::post(url + "getLastMove", "text/json", request.dump());
    if (response.code == 200) {
        json responseObj = json::parse(response.body);
        Coordinate from(responseObj["from"]["x"], responseObj["from"]["y"]);
        Coordinate to(responseObj["to"]["x"], responseObj["to"]["y"]);
        success(from, to);
    }
}

vector<string> ChessServerAPI::getAvalibleServers() {
    vector<string> tempServerNames;
    tempServerNames.push_back("Test server 1");
    tempServerNames.push_back("Test server 2");
    tempServerNames.push_back("Test server 3");
}











