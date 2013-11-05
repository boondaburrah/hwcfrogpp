//
//  Sprite.cpp
//  hwcfrog
//
//  Created by Luke A. Berry on 11/4/13.
//  Copyright (c) 2013 Sputwiler. All rights reserved.
//

#include "Sprite.h"

Sprite::Sprite(){
    
}

Sprite::~Sprite(){
    if(this->texture){
        SDL_DestroyTexture(this->texture);
    }
}

void Sprite::loadImage(SDL_Renderer* renderer, std::string fileName){
    SDL_Surface* spriteSurf = SDL_LoadBMP(fileName.c_str());
    SDL_SetColorKey(spriteSurf, SDL_TRUE, SDL_MapRGB(spriteSurf->format, 0xFF, 0x00, 0xFF));
    this->texture = SDL_CreateTextureFromSurface(renderer, spriteSurf);
    SDL_FreeSurface(spriteSurf);
    
    this->rect.x = 0;
    this->rect.y = 0;
    SDL_QueryTexture(this->texture, NULL, NULL, &this->rect.w, &this->rect.h);
}

void Sprite::draw(SDL_Renderer* renderer, int x, int y){
    this->rect.x = x;
    this->rect.y = y;
    SDL_RenderCopy(renderer, this->texture, NULL, &this->rect);
}