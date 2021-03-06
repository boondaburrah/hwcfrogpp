//
//  Game.h
//  hwcfrog
//
//  Created by Luke A. Berry on 10/29/13.
//  Copyright (c) 2013 Sputwiler. All rights reserved.
//

#ifndef __hwcfrog__Game__
#define __hwcfrog__Game__

#include <iostream>
#include <SDL2/SDL.h>
#include "VirtKeys.h"
#include "GameWorld.h"

class Game{
private:
    SDL_Window* mainWindow = NULL;
    SDL_Renderer* mainRenderer = NULL;
    SDL_GameController* gamePad = NULL;
    const int width = 320;
    const int height = 480;
    bool running;
    void processEvents();
    VirtKeys vKeys;
    GameWorld* gWorld;
public:
    Game();
    ~Game();
    void gameLoop();
};


#endif /* defined(__hwcfrog__Game__) */
