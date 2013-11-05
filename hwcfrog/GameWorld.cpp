//
//  GameWorld.cpp
//  hwcfrog
//
//  Created by Luke A. Berry on 11/1/13.
//  Copyright (c) 2013 Sputwiler. All rights reserved.
//

#include "GameWorld.h"

GameWorld::GameWorld(SDL_Renderer* renderer){
    this->renderer = renderer;
    // dunno what do here yet.
    // gonna hard-code a shit-tonne of sprites, bear with me.
    this->sprites["turtleUp"] = *new Sprite(this->renderer, "../Resources/turtle-up.bmp");
    this->sprites["turtleDown"] = *new Sprite(this->renderer, "../Resources/turtle-down.bmp");
    this->sprites["startLog"] = *new Sprite(this->renderer, "../Resources/log-start.bmp");
    this->sprites["midLog"] = *new Sprite(this->renderer, "../Resources/log-cont.bmp");
    this->sprites["endLog"] = *new Sprite(this->renderer, "../Resources/log-end.bmp");
    this->sprites["startCar"] = *new Sprite(this->renderer, "../Resources/car-start.bmp");
    this->sprites["endCar"] = *new Sprite(this->renderer, "../Resources/car-end.bmp");
    this->sprites["startTruck"] = *new Sprite(this->renderer, "../Resources/truck-start.bmp");
    this->sprites["midTruck"] = *new Sprite(this->renderer, "../Resources/truck-cont.bmp");
    this->sprites["endTruck"] = *new Sprite(this->renderer, "../Resources/truck-end.bmp");
    this->sprites["bush"] = *new Sprite(this->renderer, "../Resources/bush.bmp");
    this->sprites["sidewalk"] = *new Sprite(this->renderer, "../Resources/sidewalk.bmp");
    this->sprites["frog"] = *new Sprite(this->renderer, "../Resources/frog.bmp");
}

GameWorld::~GameWorld(){
    this->renderer = NULL;
}

void GameWorld::draw(){
    // jack shit to draw at the moment.
    SDL_RenderClear(this->renderer);
    this->sprites["turtleUp"].draw(this->renderer, 0, 0);
    SDL_RenderPresent(this->renderer);
}

void GameWorld::tick(int dt, VirtKeys vk){
    
}

