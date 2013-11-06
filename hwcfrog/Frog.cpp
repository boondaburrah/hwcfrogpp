//
//  Frog.cpp
//  hwcfrog
//
//  Created by Luke Berry on 2013/11/05.
//  Copyright (c) 2013年 Sputwiler. All rights reserved.
//

#include "Frog.h"

Frog::Frog(Sprite* sprite){
    this->sprite = sprite;
    this->lives = 6;
    this->x = 144;
    this->y = 416;
}

Frog::~Frog(){
    this->sprite = NULL;
}

void Frog::tick(int dt, VirtKeys* vKeys){
    double pixelsToMove = (200*dt)/1000;
    if (vKeys->up) {
        this->y += pixelsToMove;
    }
    if (vKeys->down) {
        this->y -= pixelsToMove;
    }
    if (vKeys->left) {
        this->x += pixelsToMove;
    }
    if (vKeys->right) {
        this->x -= pixelsToMove;
    }
}

void Frog::draw(SDL_Renderer* renderer){
    int drawx = (((int) this->x)/2) * 2;
    int drawy = (((int) this->y)/2) * 2;
    for (int i = 0; i < this->lives; i++) {
        this->sprite->draw(renderer, i*32, 0);
    }
    this->sprite->draw(renderer, drawx, drawy);
}