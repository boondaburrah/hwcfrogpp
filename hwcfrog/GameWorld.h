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
#include "VirtKeys.h"

class GameWorld {
    
    
public:
    GameWorld();
    ~GameWorld();
    void draw();
    void tick(int, VirtKeys);
};

#endif /* defined(__hwcfrog__GameWorld__) */
