//
//  Sprite.h
//  hwcfrog
//
//  Created by Luke A. Berry on 11/4/13.
//  Copyright (c) 2013 Sputwiler. All rights reserved.
//

#ifndef __hwcfrog__Sprite__
#define __hwcfrog__Sprite__

#include <iostream>
#include <SDL2/SDL.h>
#include <string.h>

class Sprite {
    SDL_Texture* texture;
    SDL_Rect rect;
public:
    Sprite();
    Sprite(SDL_Renderer*, std::string);
    ~Sprite();
    void loadImage(SDL_Renderer*, std::string);
    void draw(SDL_Renderer*, int, int);
};

#endif /* defined(__hwcfrog__Sprite__) */
