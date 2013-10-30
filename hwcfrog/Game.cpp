//
//  Game.cpp
//  hwcfrog
//
//  Created by Luke A. Berry on 10/29/13.
//  Copyright (c) 2013 Sputwiler. All rights reserved.
//

#include "Game.h"

Game::Game(){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
    
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
    
    this->mainWindow = SDL_CreateWindow("Highway Crossing Frog", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, SDL_WINDOW_SHOWN);
    this->mainSurface = SDL_GetWindowSurface(this->mainWindow);
    
    if(SDL_NumJoysticks() > 0){
        for (int i = 0; i < SDL_NumJoysticks(); i++) {
            if(SDL_IsGameController(i)){
                this->gamePad = SDL_GameControllerOpen(i);
                if(this->gamePad){
                    printf("Opened controller %i\n", i);
                } else {
                    printf("Failed to open controller %i\n", i);
                }
            }
        }
    }
    
    this->running = true;
}

Game::~Game(){
    SDL_GameControllerClose(this->gamePad);
    
    SDL_DestroyWindow(this->mainWindow);
    this->mainWindow = NULL;
    
    SDL_Quit();
}

void Game::processEvents(){
    SDL_Event event;
    
    while(SDL_PollEvent(&event) != 0){
        if(event.type == SDL_QUIT){
            this->running = false;
        } else if(event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    this->vKeys.up = true;
                    break;
                case SDLK_DOWN:
                    this->vKeys.down = true;
                    break;
                case SDLK_LEFT:
                    this->vKeys.left = true;
                    break;
                case SDLK_RIGHT:
                    this->vKeys.right = true;
                    break;
                    
                default:
                    break;
            }
        } else if(event.type == SDL_KEYUP){
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    this->vKeys.up = false;
                    break;
                case SDLK_DOWN:
                    this->vKeys.down = false;
                    break;
                case SDLK_LEFT:
                    this->vKeys.left = false;
                    break;
                case SDLK_RIGHT:
                    this->vKeys.right = false;
                    break;
                default:
                    break;
            }
        }
    }
}

void Game::gameLoop(){
    while(this->running){
        this->processEvents();
    }
}