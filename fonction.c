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




const int personnage_SPEED = 5;



void initialiser_imageBACK(image *imge)
{
    imge->url="images/background";
    imge->img=IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("erreur img background %s\n", SDL_GetError());
        return ;
    }
    	imge->pos_img_ecran.x=0;
	imge->pos_img_ecran.y=0;
	imge->pos_img_affiche.w=0;
	imge->pos_img_affiche.h=0;
	imge->pos_img_affiche.h=SCREEN_H;
	imge->pos_img_affiche.w=SCREEN_W;  
}

void afficher_imageBACK(SDL_Surface *screen,image imge)
{
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran );
}


void init_personnage(personnage* personnage,  char* image_path1, int x, int y) 
{
    
    personnage->surface = IMG_Load(image_path1);

    
    personnage->x = x;
    personnage->y = y;

    
    personnage->dx = 0;
    personnage->dy = 0;
}

void init_personnage2(personnage* personnage,  char* image_path2, int x, int y) 
{
    
    personnage->surface = IMG_Load(image_path2);

    
    personnage->x = x;
    personnage->y = y;

    
    personnage->dx = 0;
    personnage->dy = 0;
}
    
     
void saut(personnage* personnage) 
{
    personnage->dy = -15;  
    personnage->saut = 1;  
    personnage->dx = 5;
    
    
}

void deplacement_personnage(personnage* personnage)
{
    
    personnage->x += personnage->dx;
    personnage->y += personnage->dy;    
    personnage->dy += GRAVITY;
    
    
    if (personnage->y >= GROUND_HEIGHT) {
        personnage->y = GROUND_HEIGHT;
        personnage->dy = 0;
        personnage->dx = 0;
        personnage->saut = 0;
    }
    
}


/*void deplacer_personnage1(personnage * personnage1, int right, int left, int rightS)
{
    personnage1->dx = left;
    personnage1->dx = rightS;
    personnage1->dx = right;

}

void deplacer_personnage2(personnage * personnage2, int right2, int left2, int rightS)
{
    personnage2->dx = left2;
    personnage2->dx = right2;

}

*/

void afficher_personnage(personnage* personnage, SDL_Surface* screen) 
{

    personnage->x += personnage->dx;
    personnage->y += personnage->dy;

    
    SDL_Rect rect = {personnage->x, personnage->y, personnage->surface->w, personnage->surface->h};

    
    SDL_BlitSurface(personnage->surface, NULL, screen, &rect);
}




/*Uint32 animate_timer_callback(Uint32 interval, void* param) {
    SDL_Event event;
    event.type = SDL_USEREVENT;
    SDL_PushEvent(&event);
    return interval;
}

void animate_character(personnage personnage,SDL_Surface** frames, int num_frames, int animation_speed) {
    SDL_Surface* screen = NULL;
    
    SDL_Event event;
    int quit = 0;
    int frame = 0;
    image background;
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(1600, 900, 32, SDL_SWSURFACE);

    
    SDL_TimerID timer_id = SDL_AddTimer(animation_speed, animate_timer_callback, NULL);

    
    initialiser_imageBACK(&background);
    //SDL_FillRect(&background, NULL, SDL_MapRGB(background->format, 255, 255, 255));

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
            else if (event.type == SDL_USEREVENT) {
                // Update the frame counter
                frame++;
                if (frame >= num_frames) {
                    frame = 0;
                }
            }
        }

    
        SDL_BlitSurface(&background, NULL, screen, NULL);

        SDL_Rect frame_rect;
        frame_rect.x = personnage.dx;
        frame_rect.y = personnage.dy;
        frame_rect.w = frames[frame]->w;
        frame_rect.h = frames[frame]->h;
        SDL_BlitSurface(frames[frame], NULL, &background, &frame_rect);

        
        SDL_Flip(screen);
        afficher_imageBACK(screen,background);
        
    }

    
    SDL_RemoveTimer(timer_id);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(&background);
    for (int i = 0; i < num_frames; i++) {
        SDL_FreeSurface(frames[i]);
    }
    SDL_Quit();
}
*/




