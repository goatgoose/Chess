
/*
 Author: Sam Clark, Craig Conway
 Class: CSI-240
 Assignment: Final Project
 Date Assigned: 11/16/2016
 Due Date: 12/12/2016, 11:59 PM
 Description:
 "Chess"
 Certification of Authenticity:
 I certify that this is entirely my own work, except where I have given
 fully-documented references to the work of others. I understand the
 definition and consequences of plagiarism and acknowledge that the assessor
 of this assignment may, for the purpose of assessing this assignment:
 - Reproduce this assignment and provide a copy to another member of
 academic staff; and/or
 - Communicate a copy of this assignment to a plagiarism checking
 service (which may then retain a copy of this assignment on its database
 for the purpose of future plagiarism checking)
 */

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
