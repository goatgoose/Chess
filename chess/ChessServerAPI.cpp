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
#include "ChessWindow.hpp"

string url = "http://localhost:4567/";
int timeout = 5; // seconds

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
    } else {
        cout << "failed creating game: will try again in " << timeout << " seconds" << endl;
        board->game->addTimer(new Timer(timeout, [=] {
            createGame(board, success);
        }));
    }
}

void ChessServerAPI::deleteGame(ChessBoard* board, function<void()> success) {
    json request;
    request["game"] = board->game->getName();
    
    RestClient::Response response = RestClient::post(url + "deleteGame", "text/json", request.dump());
    if (response.code == 200) {
        success();
    } else {
        cout << "failed deleting game: will try again in " << timeout << " seconds" << endl;
        board->game->addTimer(new Timer(timeout, [=] {
            deleteGame(board, success);
        }));
    }
}

void ChessServerAPI::isWaiting(ChessBoard* board, function<void(bool isWaiting)> success) {
    json request;
    request["game"] = board->game->getName();
    
    RestClient::Response response = RestClient::post(url + "isWaiting", "text/json", request.dump());
    if (response.code == 200) {
        json responseObj = json::parse(response.body);
        success(responseObj["isWaiting"]);
    } else {
        cout << "failed getting waiting status: will try again in " << timeout << " seconds" << endl;
        board->game->addTimer(new Timer(timeout, [=] {
            isWaiting(board, success);
        }));
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
    } else {
        cout << "failed updating piece location: will try again in " << timeout << " seconds" << endl;
        board->game->addTimer(new Timer(timeout, [=] {
            movePiece(board, from, to, success);
        }));
    }
}

void ChessServerAPI::getLastTurn(ChessBoard* board, function<void(string lastTurn)> success) {
    json request;
    request["game"] = board->game->getName();
    
    RestClient::Response response = RestClient::post(url + "getLastTurn", "text/json", request.dump());
    if (response.code == 200) {
        json responseObj = json::parse(response.body);
        success(responseObj["turn"]);
    } else {
        cout << "failed getting last turn: will try again in " << timeout << " seconds" << endl;
        board->game->addTimer(new Timer(timeout, [=] {
            getLastTurn(board, success);
        }));
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
    } else {
        cout << "failed getting last move: will try again in " << timeout << " seconds" << endl;
        board->game->addTimer(new Timer(timeout, [=] {
            getLastMove(board, success);
        }));
    }
}

void ChessServerAPI::getAvailableServers(ChessWindow* window, function<void(vector<string> servers)> success) {
    RestClient::Response response = RestClient::get(url + "availableServers");
    if (response.code == 200) {
        json responseObj = json::parse(response.body);
        success(responseObj["servers"]);
    } else {
        cout << "failed getting available servers: will try again in " << timeout << " seconds" << endl;
        window->addTimer(new Timer(timeout, [=] {
            getAvailableServers(window, success);
        }));
    }
}











