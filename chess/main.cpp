
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
#include <MainWindow.hpp>
#include <Button.hpp>

// TODO
// https://docs.google.com/spreadsheets/d/1IAaIWOks1xy_ooIK4-HwEAsOXJJnhxrV7eh4zF4xzxc/edit?usp=sharing

using namespace sf;
using namespace std;

int main(int, char const**) {
    
    MainWindow* mainWindow = new MainWindow();
       mainWindow->launch();
    
    
    
    return EXIT_SUCCESS;
}
