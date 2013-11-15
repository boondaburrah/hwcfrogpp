//
//  Hazard.h
//  hwcfrog
//
//  Created by Luke Berry on 2013/11/09.
//  Copyright (c) 2013年 Sputwiler. All rights reserved.
//

#ifndef __hwcfrog__Hazard__
#define __hwcfrog__Hazard__

#define HAZARD_DIRECTION_LEFT true
#define HAZARD_DIRECTION_RIGHT false
#define HAZARD_DIRECTION_THRESHOLD 200

#include <iostream>
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "VirtKeys.h"

class Hazard {
    Sprite* startSprite;
    Sprite* midSprite;
    Sprite* endSprite;
    double x;
    double y;
    int lastSwitched;
    int length;
    bool direction;
    bool safe;
    bool switching;
public:
    Hazard();
    ~Hazard();
    Hazard(double x, double y, Sprite* sprite, int length);
    Hazard(double x, double y, Sprite* left, Sprite* right);
    Hazard(double x, double y, Sprite* left, Sprite* center, Sprite* right, int length, bool safe);
    Hazard(double x, double y, Sprite* safe, Sprite* unsafe, int length);
    bool getSafe();
    void tick(double, VirtKeys*);
    void draw(SDL_Renderer*);
};

#endif /* defined(__hwcfrog__Hazard__) */
