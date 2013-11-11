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
    if (this->x > 300) {
        this->direction = HAZARD_DIRECTION_LEFT;
    } else {
        this->direction = HAZARD_DIRECTION_RIGHT;
    }
    this->length = length;
}

Hazard::Hazard(double x, double y, Sprite* left, Sprite* right){
    
}

Hazard::Hazard(double x, double y, Sprite* left, Sprite* center, Sprite* right, int length){
    
}

Hazard::Hazard(double x, double y, Sprite* safe, Sprite* unsafe, int length){
    
}
