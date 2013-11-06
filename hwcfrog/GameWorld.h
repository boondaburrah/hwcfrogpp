//
//  GameWorld.h
//  hwcfrog
//
//  Created by Luke A. Berry on 11/1/13.
//  Copyright (c) 2013 Sputwiler. All rights reserved.
//

#ifndef __hwcfrog__GameWorld__
#define __hwcfrog__GameWorld__

#include <iostream>
#include <SDL2/SDL.h>
#include <unordered_map>
#include <string.h>
#include "VirtKeys.h"
#include "Sprite.h"
#include "Frog.h"

class GameWorld {
    std::unordered_map<std::string, Sprite> sprites;
    SDL_Renderer* renderer;
    Frog* frog;
public:
    GameWorld(SDL_Renderer*);
    ~GameWorld();
    void draw();
    void tick(int, VirtKeys*);
private:
    void drawBackground();
};

#endif /* defined(__hwcfrog__GameWorld__) */
