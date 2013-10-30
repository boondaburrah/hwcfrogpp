//
//  main.cpp
//  hwcfrog
//
//  Created by Luke A. Berry on 10/29/13.
//  Copyright (c) 2013 Sputwiler. All rights reserved.
//

#include "main.h"
#include "Game.h"

int main(void){
    Game* game = new Game();
    
    game->gameLoop();
    
    delete game;
    
    return 0;
}