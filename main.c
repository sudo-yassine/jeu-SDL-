
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "enigme.h"
#include "temps.h"

int main()
{
    enigme enig;
    int quit=1;
    int tempstart,tempnow,choix_rep=0;
	int count=0;
	int screen_num=1;
	int mousex,mousey;
	int random_enigme;
	temps timer;
	Uint32 locate;
	float zoom=0.1,angle=0;
	char src[20];
	TTF_Init();
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		printf("Can't init SDL:  %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}
	SDL_Surface *screen,*background,*background2;
	image hardluck,good,pluie;
	SDL_Event e;
	SDL_Rect posenig;
	screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_RESIZABLE);
	if (screen == NULL)
	{
		printf("Can't set video mode: %s\n", SDL_GetError());
		return 1;
	}
    good.img=IMG_Load("good.png");
	hardluck.img=IMG_Load("hardluck.png");
	background=IMG_Load("background.png");
	int i;
	char url_animated[20];
	for(i=0;i<27;i++)
	{
		
		sprintf(url_animated,"animation/%d.png",i);
		pluie.animated[i]=IMG_Load(url_animated);
		if(pluie.animated[i]==NULL)
		printf("ERROR LOAD IMG");
	}

	
    posenig.x=0 ;
	posenig.y=0;

	SDL_Rect rep1;
	SDL_Rect rep2;
	SDL_Rect rep3;
	
	rep1.x=212;
	rep1.y=400;
	rep1.w=418;
	rep1.h=426;
	
	rep2.x=779;	
	rep2.y=400;
	rep2.w=418;
	rep2.h=426;
	
	rep3.x=1352;
	rep3.y=400;
	rep3.w=418;
	rep3.h=426;


    tempstart=SDL_GetTicks();

	while (quit == 1)
	{
		switch(screen_num)
		{
		case 1:
		SDL_BlitSurface(background,NULL,screen,NULL);
        SDL_Flip(screen);
		if(SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
			{
				quit = 0;
			}
			break;    
        	}
			switch(e.key.keysym.sym)
			{
				case SDLK_p:
					srand(time(NULL));
					random_enigme = rand() % 3;
					sprintf(src,"%d.txt",random_enigme);
					generer(&enig,src);
					initialiser_temps(&timer);
					screen_num=2;
				break;
			}

		}
		break;

		case 2:
		locate=SDL_GetMouseState(&mousex,&mousey);
		afficherEnigme(enig,screen);
		afficher_temps(&timer,screen);
		SDL_BlitSurface(pluie.animated[count],NULL,screen,NULL);
		SDL_Flip(screen);

		count++;
		if(count>=27)
		{
			count=0;
		}
		if(SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
			{
				quit = 2;
			}
			break;
			case SDL_KEYDOWN: 
				if(e.key.keysym.sym==SDLK_KP1 || e.key.keysym.sym==SDLK_KP2 || e.key.keysym.sym==SDLK_KP3 ){
				

				if(e.key.keysym.sym==SDLK_KP1 && enig.rep==1)
       			 {				   
         		   enig.enigme_state=1;
       			 }
				else if(e.key.keysym.sym==SDLK_KP2 && enig.rep==2)
				{
				   
         		   enig.enigme_state=1;
       			 }
				
				else if(e.key.keysym.sym==SDLK_KP3 && enig.rep==3)
				{	   
         		  enig.enigme_state=1;
       			}
				else{
					if(e.key.keysym.sym==SDLK_KP1 || e.key.keysym.sym==SDLK_KP2 || e.key.keysym.sym==SDLK_KP3)
					enig.enigme_state=-1;
				}
				}
			break;
			case SDL_MOUSEBUTTONDOWN: 
				if(e.button.button== SDL_BUTTON_LEFT ){
				

				if(intersection_souris(rep1,mousex,mousey)==1 && enig.rep==1)
       			 {				   
         		   enig.enigme_state=1;
       			 }
				else if(intersection_souris(rep2,mousex,mousey)==1 && enig.rep==2)
				{
				   
         		   enig.enigme_state=1;
       			 }
				
				else if(intersection_souris(rep3,mousex,mousey)==1 && enig.rep==3)
				{
					enig.enigme_state=1;
       			}
				else{
					if(intersection_souris(rep1,mousex,mousey)==1 || intersection_souris(rep2,mousex,mousey)==1 || intersection_souris(rep3,mousex,mousey)==1)
				enig.enigme_state=-1;
				}
			break;
			}}
	}





		if(enig.enigme_state==1)
			{
				SDL_BlitSurface(good.img,NULL,screen,NULL);
				SDL_Flip(screen);
				SDL_Delay(2000);
				screen_num=1;
				   
			}
			else if(enig.enigme_state==-1)
			{
				SDL_BlitSurface(hardluck.img,NULL,screen,NULL);
				SDL_Flip(screen);
				SDL_Delay(2000);
				screen_num=1;
			}
			else{
				enig.tempactuel=SDL_GetTicks();
				if((enig.tempactuel-enig.tempstart)>=20000)
				{
					screen_num=1;
					SDL_BlitSurface(hardluck.img,NULL,screen,NULL);
					SDL_Flip(screen);
					SDL_Delay(2000);
					
					
				}
			}
	
	}
	}
	SDL_Quit();
	return 0;
}
