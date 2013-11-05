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
    this->sprites["turtleUp"] = *new Sprite;
    this->sprites["turtleUp"].loadImage(this->renderer, "../Resources/turtle-up.bmp");
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

