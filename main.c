#include "test.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
        atexit(SDL_QUIT);
   time_t t;
   srand((unsigned) time(&t));
	SDL_Surface* screen = SDL_SetVideoMode(1032, 573, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	Person p;
	Image bg;
	Map m;
	SDL_Event event;
	int quit = 0;
    Uint32 start_time = SDL_GetTicks();

init_Background (&bg);
init_Person (&p);
init_Map (&m);
    while (!quit) {	
	

	afficher_mask(bg,screen);
	afficher_bg(bg,screen);
	afficher_Person(p,screen);
	afficher_Map(m,screen);
	afficher_temps(start_time,screen);
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_KEYDOWN:

                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            p.pos1.y -= 10;
                            if (p.pos1.y < 0) {
                                p.pos1.y = 0;
                            }
			UpdateCoord(&p);
                            break;
                        case SDLK_DOWN:
                            p.pos1.y += 10;
                            if (p.pos1.y > screen->h - p.pos2.h) {
                                p.pos1.y = screen->h - p.pos2.h;
                            }
                            break;
			UpdateCoord(&p);
                        case SDLK_LEFT:
                            p.pos1.x -= 10;
                            if (p.pos1.x < 0) {
                                p.pos1.x = 0;
                            }
                            break;
			UpdateCoord(&p);
                        case SDLK_RIGHT:
                            p.pos1.x += 10;
                            if (p.pos1.x > screen->w - p.pos2.w) {
                                p.pos1.x = screen->w - p.pos2.w;
                            }
			UpdateCoord(&p);
                            break;
                    }
                    break;
            }
        }

        // Update dot position in the map
        m.posdot.x =  (p.pos1.x / (float)screen->w) * m.posmap.w;
        m.posdot.y =  (p.pos1.y / (float)screen->h) * m.posmap.h;


	if(CollisionPP(&p,bg.mask))
	{                            p.pos1.x += 10;

	}

       
        SDL_Flip(screen);
    }
 liberer(bg);
 liberer_Person(p);
 liberer_Map(m);
	TTF_Quit();

    SDL_Quit();

    return 0;
}
