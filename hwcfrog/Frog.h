//
//  Frog.h
//  hwcfrog
//
//  Created by Luke Berry on 2013/11/05.
//  Copyright (c) 2013年 Sputwiler. All rights reserved.
//

#ifndef __hwcfrog__Frog__
#define __hwcfrog__Frog__

#define FROG_START_X 144
#define FROG_START_Y 416

#include <iostream>
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "VirtKeys.h"

class Frog {
    int lives;
    double x;
    double y;
    Sprite* sprite;
public:
    Frog(Sprite*);
    ~Frog();
    void tick(int, VirtKeys*);
    void draw(SDL_Renderer*);
    void die();
};

#endif /* defined(__hwcfrog__Frog__) */
