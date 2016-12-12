//
//  MainWindow.hpp
//  chess
//
//  Created by Craig Conway


#ifndef MainWindow_hpp
#define MainWindow_hpp

#include <ChessWindow.hpp>
#include <MultiplayerWindow.hpp>
#include <ChessGame.hpp>
#include <Button.hpp>

class MainWindow: public ChessWindow {
public:
    MainWindow();

private:
    Button* localButton;
    Button* multiplayerButton;
};


#endif /* MainWindow_hpp */
