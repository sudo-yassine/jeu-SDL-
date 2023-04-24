
#include "background.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

int main()
{

    SDL_Surface *screen = SDL_SetVideoMode(1500, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); 

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); 

    SDL_Event event; 

    SDL_Surface *perso = IMG_Load("perso.png"); 

    SDL_Rect posPerso = {0,499}; 
    
    int continuer = 1; 
    int direction = -1; 

   
    Uint32 start, prev, dt; 
    const int FPS = 30; 

    Background B;
    ScoreInfo player;  
    
    initBackground(&B); 

    strcpy(player.name,"hajer");
    player.score=B.score;
    player.time=SDL_GetTicks();

    while (continuer==1)
    {
        start = SDL_GetTicks();

        affBackground(&B, screen);

        SDL_BlitSurface(perso, NULL, screen, &posPerso); 
        animerBack(&B);
        scrolling(&B, posPerso, direction);

        if (direction == 1)
        {
            if (posPerso.x < 750) 
                posPerso.x += 30; 
            else if (B.camera.x >= 10000 -1500 ) 
                posPerso.x += 10;
        }

        if (direction == 0) 
        {
            if (posPerso.x > 750)
                posPerso.x -= 10;
            else if ((B.camera.x == 0) && (posPerso.x > 0))
                posPerso.x -= 10; 
        }

        while (SDL_PollEvent(&event)) 
{
    switch (event.type) 
    {
    case SDL_QUIT: 
        continuer = 0;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_RIGHT:
            direction = 1;
            break;
        case SDLK_LEFT: 
            direction = 0; 
            break;
        case SDLK_UP: 
            B.score += 10;
            break;
        case SDLK_DOWN: 
            B.score -= 10; 
            break;
        case SDLK_a: 
            B.vie += 10; 
            break;
        case SDLK_z: 
            B.vie -= 10; 
            break;
        case SDLK_SPACE:
            direction=1;
            direction=0;
	case SDLK_SPACE:
		player.score=B.score;
   		player.time=SDL_GetTicks();
		sauvegarder(player,"player.txt");
	break;
        }
        break;
    case SDL_KEYUP: 
        switch (event.key.keysym.sym) 
        {
        case SDLK_RIGHT: 
            direction=-1;
        break;
        case SDLK_LEFT: 
            direction = -1; 
            break;
        }
        break;
    }
}

        SDL_Flip(screen);
        if (1000 / FPS > SDL_GetTicks() - start)
            SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
    }




    SDL_FreeSurface(screen); 
    freeBackground(&B);
    return 0;
}
