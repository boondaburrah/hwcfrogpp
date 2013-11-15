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
    
    this->frog = new Frog(&this->sprites["frog"]);
    this->testHazard = new Hazard(240, 300, &this->sprites["startTruck"], &this->sprites["midTruck"], &this->sprites["endTruck"], 4, false);
}

GameWorld::~GameWorld(){
    delete this->frog;
    this->renderer = NULL;
    this->sprites.clear();
}

void GameWorld::draw(){
    // jack shit to draw at the moment.
    SDL_RenderClear(this->renderer);
    //this->sprites["turtleUp"].draw(this->renderer, 0, 0);
    this->drawBackground();
    this->frog->draw(this->renderer);
    this->testHazard->draw(this->renderer);
    SDL_RenderPresent(this->renderer);
}

void GameWorld::tick(int dt, VirtKeys* vk){
    this->frog->tick(dt, vk);
    this->testHazard->tick(dt, vk);
}

void GameWorld::drawBackground(){
    SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0xCC, 0xFF);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 32;
    rect.w = 320;
    rect.h = 192;
    SDL_RenderFillRect(this->renderer, &rect);
    SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0xFF);
    for (int i = 0; i < 320; i += 32) {
        this->sprites["bush"].draw(this->renderer, i, 32);
        this->sprites["sidewalk"].draw(this->renderer, i, 224);
    }
}