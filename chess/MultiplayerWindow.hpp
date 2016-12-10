//
//  MultiplayerWindow.hpp
//  chess
//
//  Created by Craig Conway on 12/10/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#ifndef MultiplayerWindow_hpp
#define MultiplayerWindow_hpp

#include <ChessWindow.hpp>
#include <ChessGame.hpp>
#include <Button.hpp>

class MultiplayerWindow: public ChessWindow {

public:
    MultiplayerWindow();
    
private:
    Button* joinButton;
    Button* hostButton;
    Button* backButton;
    virtual void resizeEvent(Event event) override;
    
    
};



#endif /* MultiplayerWindow_hpp */
