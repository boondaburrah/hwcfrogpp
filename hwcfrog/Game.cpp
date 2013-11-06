//
//  Game.cpp
//  hwcfrog
//
//  Created by Luke A. Berry on 10/29/13.
//  Copyright (c) 2013 Sputwiler. All rights reserved.
//

#include "Game.h"

#define GASIA_PS2_MAP "8f0e0000000000000300000000000000,GreenAsia Dualshock 2 Adapter,a:b2,b:b1,y:b0,x:b3,start:b9,back:b8,leftstick:b10,rightstick:b11,leftshoulder:b6,rightshoulder:b7,dpup:h0.1,dpleft:h0.8,dpdown:h0.4,dpright:h0.2,leftx:a0,lefty:a1,rightx:a3,righty:a2,lefttrigger:b4,righttrigger:b5,"
#define GASIA_PS2_LIN "030000008f0e00000300000010010000,GreenAsia Dualshock 2 Adapter Linux,a:b2,b:b1,y:b0,x:b3,start:b9,back:b8,leftstick:b10,rightstick:b11,leftshoulder:b6,rightshoulder:b7,dpup:h0.1,dpleft:h0.8,dpdown:h0.4,dpright:h0.2,leftx:a0,lefty:a1,rightx:a3,righty:a2,lefttrigger:b4,righttrigger:b5,"

Game::Game(){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
    
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
    
    this->mainWindow = SDL_CreateWindow("Highway Crossing Frog", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, SDL_WINDOW_SHOWN);
    
    this->mainRenderer = SDL_CreateRenderer(this->mainWindow, -1, SDL_RENDERER_ACCELERATED);
    
    if(SDL_GameControllerAddMapping(GASIA_PS2_MAP) == 1){
        printf("Managed to add silly PS2 adapter thing.\n");
    }
    if(SDL_GameControllerAddMapping(GASIA_PS2_LIN) == 1){
        printf("Managed to add silly PS2 adapter thing on Linux.\n");
    }
    
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
    } else {
        printf("No controllers found.\n");
    }
    
    this->gWorld = new GameWorld(this->mainRenderer);
    
    this->running = true;
}

Game::~Game(){
    SDL_GameControllerClose(this->gamePad);
    
    delete this->gWorld;
    
    SDL_DestroyRenderer(this->mainRenderer);
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
    
    if (this->gamePad) {
        this->vKeys.up = SDL_GameControllerGetButton(this->gamePad, SDL_CONTROLLER_BUTTON_DPAD_UP);
        this->vKeys.down = SDL_GameControllerGetButton(this->gamePad, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
        this->vKeys.left = SDL_GameControllerGetButton(this->gamePad, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
        this->vKeys.right = SDL_GameControllerGetButton(this->gamePad, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
        if (SDL_GameControllerGetButton(this->gamePad, SDL_CONTROLLER_BUTTON_BACK)) {
            this->running = false;
        }
    }
}

void Game::gameLoop(){
    int lastTime = SDL_GetTicks();
    int now = lastTime;
    int dtms = 0;
    while(this->running){
        now = SDL_GetTicks();
        dtms = lastTime - now;
        lastTime = now;
        this->processEvents();
        this->gWorld->tick(dtms, &vKeys);
        this->gWorld->draw();
    }
}