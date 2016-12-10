
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ChessGame.hpp>
#include <Button.hpp>

// TODO
// call update to all clickables- dont manually update
// button class
//   make scalable
//   positioned in percents
// multiplayer server
//   matchmaking / elo system ?
// moves log (new window?)
// host / join / find game menu
//   go to this first before actual chess game
// timer system
// capture functionality
// show captured pieces
// test for checkmate every move, if no possible moves u lose
// in game buttons
//   surrender
//   ask for draw (won't effect mmr)

using namespace sf;
using namespace std;

int main(int, char const**) {
    
    ChessGame* chessGame = new ChessGame(900);
    chessGame->launch();
    
    return EXIT_SUCCESS;
}
