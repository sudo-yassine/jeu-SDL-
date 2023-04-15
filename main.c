#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "header.h"


#define SCREEN_H 1600
#define SCREEN_W 919
#define GRAVITY 1
#define GROUND_HEIGHT 650
#define JUMP_HEIGHT 400
#define personnage_WIDTH 200
#define personnage_HEIGHT 200
#define MAX_DX 5.0
#define MAX_DY 5.0
#define ANIMATION_SPEED 5


int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
    SDL_Surface* screen = SDL_SetVideoMode(1600, 919, 32, SDL_DOUBLEBUF | SDL_HWSURFACE);
    image background;
    initialiser_imageBACK(&background);
    int right,rightS,left,right2,left2;
    char r1[50],r2[50],l1[50],l2[50];
    personnage personnage1;
    personnage personnage2;
    init_personnage(&personnage1, "images/char", 50, 650);
    init_personnage2(&personnage2, "images/char2", 150, 650);
    
    SDL_Surface* frames[4];
    frames[0] = IMG_Load("images/charWR1");
    frames[1] = IMG_Load("images/charWR2");
    frames[2] = IMG_Load("images/charWL1");
    frames[3] = IMG_Load("images/charWL2");

     
    int done =0;
    while (!done) {
	
        
        SDL_Event event;
        while (SDL_PollEvent(&event))
		if (event.type == SDL_KEYDOWN) {
            		if (event.key.keysym.sym == SDLK_SPACE && !personnage1.saut) {
                		saut(&personnage1);
            		}
        	}
                if (event.type == SDL_KEYDOWN) {
            		if (event.key.keysym.sym == SDLK_w && !personnage2.saut) {
                		saut(&personnage2);
            		}
        	}

 	{	
            if (event.type == SDL_QUIT) {
                done =1;

            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        personnage1.dx = -10;
                        //left=-10;
                        break;
                        case SDLK_LSHIFT:
                        personnage1.dx = 15;
                        //rightS=15;
                        break;
                    case SDLK_RIGHT:
                        personnage1.dx = 10;
                        //animate_character(background,personnage1,frames, 2, 100);
                        //right=10;
                        break;
                        
                        
                        
		    case SDLK_a:
                        personnage2.dx = -10;
                        //left2=-10;
                        break;
                    case SDLK_d:
                        personnage2.dx = 10;
                        //right2=10;
                        break;
		   
                    
                }
            } else if (event.type == SDL_KEYUP) {
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        personnage1.dx = 0;
                        //left=0;
                        break;
                    case SDLK_RIGHT:
                        personnage1.dx = 0;
                        //right=0;
                        break;
		    case SDLK_d:
                        personnage2.dx = 0;
                        //right2=0;
                        break;
                    case SDLK_a:
                        personnage2.dx = 0;
                        //left2=0;
                        break;
                    case SDLK_LSHIFT:
                        personnage1.dx = 0;
                        //rightS=0;
                        break;
                  
                }
            }
        }
	afficher_imageBACK(screen,background);
	//deplacer_personnage1(&personnage1, right, left,rightS);
	//deplacer_personnage2(&personnage2, right2, left2,rightS);
	deplacement_personnage(&personnage1);
	deplacement_personnage(&personnage2);
	//animation(&personnage1);
	
        afficher_personnage(&personnage1, screen);
	afficher_personnage(&personnage2, screen);
        SDL_Flip(screen);
	
    }

    
    SDL_FreeSurface(personnage1.surface);
    SDL_FreeSurface(personnage2.surface);
    SDL_Quit();

    return 0;
}

