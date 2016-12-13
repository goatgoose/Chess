//
//  ChessGame.cpp
//  chess
//
//  Created by Sam Clark and Craig Conway
//
#include "ChessGame.hpp"

ChessGame::ChessGame(int scale, string name, GameMode gameMode): ChessWindow(scale + 300, scale, Color(232, 174, 81), true) {
    this->scale = scale;
    this->name = name;
    this->gameMode = gameMode;
    this->notificationLabel = new Label("", 20, this);
    this->board = new ChessBoard(scale, gameMode, this);
    this->pickedUpPiece = nullptr;
    this->pickedUpPieceTile = nullptr;
    
    if (gameMode == MULTI_PLAYER) {
        drawButton = new Button(0.8, 0.4, 0.15, 0.075, this, [&] {cout << "Ask for draw" << endl;});
        drawButton->setColor(Color(96, 108, 131));
        drawButton->setLabel("Ask For Draw");
        
        secedeButton = new Button(0.8, 0.6, 0.15, 0.075, this, [&] {
            ChessServerAPI::deleteGame(board, [] {});
            this->renderWindow->close();
            MainWindow* mainWindow = new MainWindow();
            mainWindow->launch();
        });
        secedeButton->setColor(Color(96, 108, 131));
        secedeButton->setLabel("Surrender");
    } else {
        secedeButton = new Button(0.8, 0.6, 0.15, 0.075, this, [&] {
            ChessServerAPI::deleteGame(board, [] {});
            this->renderWindow->close();
            MainWindow* mainWindow = new MainWindow();
            mainWindow->launch();
        });
        secedeButton->setColor(Color(96, 108, 131));
        secedeButton->setLabel("Back");
    }
        
    this->board->setScale(scale);
    
    update();
}

void ChessGame::resizeEvent(Event event) {
    this->board->setScale(event.size.height);
    this->update();
    this->drawButton->update();
    this->secedeButton->update();
}

void ChessGame::closeEvent(Event event) {
    if (gameMode == MULTI_PLAYER) {
        ChessServerAPI::deleteGame(board, [] {});
    }
    this->renderWindow->close();
    MainWindow* mainWindow = new MainWindow();
    mainWindow->launch();
}

void ChessGame::update() {
    notificationLabel->text->setPosition(Vector2f(board->scale + 50, 20));
}

string ChessGame::getName() {
    return name;
}

ChessGame::~ChessGame() {
    ChessServerAPI::deleteGame(board, [] {});
    
    delete board;
    delete drawButton;
    delete secedeButton;
}
