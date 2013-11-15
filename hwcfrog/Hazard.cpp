//
//  Hazard.cpp
//  hwcfrog
//
//  Created by Luke Berry on 2013/11/09.
//  Copyright (c) 2013年 Sputwiler. All rights reserved.
//

#include "Hazard.h"

Hazard::Hazard(double x, double y, Sprite* sprite, int length){
    this->x = x;
    this->y = y;
    this->startSprite = sprite;
    this->direction = (this->x > HAZARD_DIRECTION_THRESHOLD) ? HAZARD_DIRECTION_LEFT : HAZARD_DIRECTION_RIGHT;
    this->length = length;
    this->switching = false;
    this->safe = false;
}

Hazard::Hazard(double x, double y, Sprite* left, Sprite* right){
    this->x = x;
    this->y = y;
    this->startSprite = left;
    this->endSprite = right;
    this->safe = false;
    this->switching = false;
    this->direction = (this->x > HAZARD_DIRECTION_THRESHOLD) ? HAZARD_DIRECTION_LEFT : HAZARD_DIRECTION_RIGHT;
    this->length = 2;
}

Hazard::Hazard(double x, double y, Sprite* left, Sprite* center, Sprite* right, int length, bool safe){
    this->x = x;
    this->y = y;
    this->startSprite = left;
    this->midSprite = center;
    this->endSprite = right;
    this->length = length;
    this->safe = safe;
    this->switching = false;
    this->direction = (this->x > HAZARD_DIRECTION_THRESHOLD) ? HAZARD_DIRECTION_LEFT : HAZARD_DIRECTION_RIGHT;
}

Hazard::Hazard(double x, double y, Sprite* safe, Sprite* unsafe, int length){
    this->x = x;
    this->y = y;
    this->startSprite = safe;
    this->endSprite = unsafe;
    this->length = length;
    this->switching = true;
    this->safe = true;
    this->lastSwitched = SDL_GetTicks();
    this->direction = (this->x > HAZARD_DIRECTION_THRESHOLD) ? HAZARD_DIRECTION_LEFT : HAZARD_DIRECTION_RIGHT;
}

bool Hazard::getSafe(void){
    return this->safe;
}

void Hazard::tick(double dt, VirtKeys* vk){
    double deltaPos = (dt*50)/1000; //I don't pretend to know what I was thinking here.
    if (this->switching && ((SDL_GetTicks() - this->lastSwitched) > 2000)) { // I really hope lazy evaluation is real.
        this->safe = !this->safe;
        this->lastSwitched = SDL_GetTicks();
    }
    this->x = this->direction ? (this->x + deltaPos) : (this->x - deltaPos);
}

void Hazard::draw(SDL_Renderer* renderer){
    int drawx = (this->x*2)/2;
    int drawy = (this->y*2)/2;
    if (this->switching == false) {
        switch (this->length) {
            case 1:
                this->startSprite->draw(renderer, drawx, drawy);
                break;
            case 2:
                this->startSprite->draw(renderer, drawx, drawy);
                this->endSprite->draw(renderer, drawx+32, drawy);
                break;
            default:
                for (int i = 0; i < this->length; i++) {
                    if (i == 0) {
                        this->startSprite->draw(renderer, drawx, drawy);
                    } else if (i == (this->length - 1)){
                        this->endSprite->draw(renderer, drawx+i*32, drawy);
                    } else {
                        this->midSprite->draw(renderer, drawx+i*32, drawy);
                    }
                }
                break;
        }
    } else if(this->switching){
        if (this->safe) {
            for (int i = 0; i < this->length; i++) {
                this->startSprite->draw(renderer, drawx+i*32, drawy);
            }
        } else {
            for (int i = 0; i < this->length; i++){
                this->endSprite->draw(renderer, drawx+i*32, drawy);
            }
        }
    }
}
