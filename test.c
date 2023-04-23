#include <SDL/SDL.h> 
#include "test.h"
#include <SDL/SDL_image.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>

void init_Background (Image *Backg)
{
Backg->img= IMG_Load("map.png");
Backg->mask= IMG_Load("mask.png");
 if (Backg->img == NULL) {
	printf("Unable to load bitmap: %s\n", SDL_GetError());
	return; 
	}

Backg->pos1.x=0;
Backg->pos1.y=0;
Backg->pos2.x=0;
Backg->pos2.y=0;
Backg->pos2.w=1032;
Backg->pos2.h=573;

}




void init_Person (Person *p)
{
	
	p->img= IMG_Load("grash0.png");

	p->pos1.x=500;
	p->pos1.y=500;
	p->pos2.x=0;
	p->pos2.y=0;
	p->pos2.w=100;
	p->pos2.h=77;

	p->SP[0][0]=p->pos1.x;
	p->SP[0][1]=p->pos1.y;

	p->SP[1][0]=(p->pos1.x + p->pos2.w)/2 ;
	p->SP[1][1]=p->pos1.y;

	p->SP[2][0]=p->pos1.x + p->pos2.w ;
	p->SP[2][1]=p->pos1.y;

	p->SP[3][0]=p->pos1.x;
	p->SP[3][1]=(p->pos1.y + p->pos2.h)/2;

	p->SP[4][0]=p->pos1.x;
	p->SP[4][1]=p->pos1.y + p->pos2.h;

	p->SP[5][0]=(p->pos1.x + p->pos2.w)/2 ;
	p->SP[5][1]=p->pos1.y + p->pos2.h;

	p->SP[6][0]=p->pos1.x + p->pos2.w ;
	p->SP[6][1]=p->pos1.y + p->pos2.h;

	p->SP[7][0]=p->pos1.x + p->pos2.w ;
	p->SP[7][1]=(p->pos1.y + p->pos2.h)/2;

}


void init_Map (Map *e)
{
	
	e->map= IMG_Load("pm.png");
	e->dot= IMG_Load("grash.2.png");

	e->posmap.x=0;
	e->posmap.y=0;
	e->posmap.w=249;
	e->posmap.h=138;

	e->posdot.x=100;
	e->posdot.y=70;
	e->posdot.w=27;
	e->posdot.h=21;
}


void afficher_temps(Uint32 start_time,SDL_Surface*screen){

        Uint32 time_running = SDL_GetTicks() - start_time;
  char time_string[20];
        sprintf(time_string, "Time: %d s",time_running );
        SDL_Color white = {255, 255, 255};
        SDL_Surface *text = TTF_RenderText_Solid(TTF_OpenFont("arial.ttf", 25), time_string, white);
        SDL_Rect text_pos = {900, 10, 0, 0};
        SDL_BlitSurface(text, NULL, screen, &text_pos);



}

void afficher_bg(Image p,SDL_Surface *screen)
{
	SDL_BlitSurface(p.img,&p.pos2,screen,&p.pos1);

}

void afficher_mask(Image p,SDL_Surface *screen)
{
	SDL_BlitSurface(p.mask,&p.pos2,screen,&p.pos1);

}
void afficher_Person(Person p,SDL_Surface *screen)
{
	SDL_BlitSurface(p.img,&p.pos2,screen,&p.pos1);

}
void afficher_Map(Map m,SDL_Surface *screen)
{ 
	SDL_BlitSurface(m.map,NULL,screen,&m.posmap);
	SDL_BlitSurface(m.dot,NULL,screen,&m.posdot);
	
}



void liberer(Image A)
{
	SDL_FreeSurface(A.img);
	SDL_FreeSurface(A.mask);
}
void liberer_Person(Person A)
{
	SDL_FreeSurface(A.img);
}
void liberer_Map(Map m)
{	
	SDL_FreeSurface(m.map);
	SDL_FreeSurface(m.dot);
}



int CheckMouseHover(int xmin,int xmax,int ymin,int ymax)
{
      int mouse_x, mouse_y;
  
      SDL_PumpEvents();
  
      SDL_GetMouseState(&mouse_x, &mouse_y);
      if ( ((mouse_x > xmin) && (mouse_x < xmax)) && ((mouse_y > ymin) && (mouse_y < ymax)) ) {
		return 1;
      }
	else 	return 0;

  
}

SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{ 
	SDL_Color color;
	Uint32 col=0;
	//Determiner position
	char* pPosition=(char*)pSurface->pixels; 
	pPosition+= (pSurface->pitch*y); 
	pPosition+= (pSurface->format->BytesPerPixel*x); 
	memcpy(&col,pPosition ,pSurface->format->BytesPerPixel); 

	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b); //pour convertir la couleur
	return (color); 
}

void UpdateCoord(Person *p)
{
p->SP[0][0]=p->pos1.x;
p->SP[0][1]=p->pos1.y;

p->SP[1][0]=(p->pos1.x + p->pos2.w)/2 ;
p->SP[1][1]=p->pos1.y;

p->SP[2][0]=p->pos1.x + p->pos2.w;
p->SP[2][1]=p->pos1.y;

p->SP[3][0]=p->pos1.x;
p->SP[3][1]=(p->pos1.y + p->pos2.h)/2;

p->SP[4][0]=p->pos1.x;
p->SP[4][1]=p->pos1.y + p->pos2.h;

p->SP[5][0]=(p->pos1.x + p->pos2.w)/2 ;
p->SP[5][1]=p->pos1.y + p->pos2.h;

p->SP[6][0]=p->pos1.x + p->pos2.w ;
p->SP[6][1]=p->pos1.y + p->pos2.h;

p->SP[7][0]=p->pos1.x + p->pos2.w ;
p->SP[7][1]=(p->pos1.y + p->pos2.h)/2;

}

int is_same_color(SDL_Color color1, SDL_Color color2) {
    if (color1.r == color2.r && color1.g == color2.g && color1.b == color2.b) {
        return 1;
    } 
    else 
	return 0;
}

int CollisionPP(Person *p,SDL_Surface *o)
{	
	SDL_Color color= {212, 115, 212};
	int i;
	for(i=0;i<8;i++)
	{
		if( is_same_color(color,GetPixel(o,p->SP[i][0],p->SP[i][1])))
			return 1;
		else continue;
	}
		
		return 0;
}/*
void animeminimap(pmap* m, int *ShowMapInfo) {
    
    Uint32 current_time = SDL_GetTicks();
    SDL_Surface* image =m->enm;
    if (current_time - m->last_time >= 1000) 
    {
       
        printf("\nWill Check images");
        if (*ShowMapInfo) 
        {   
        printf(">>>->> NONE");
        	//No map info to show
        	*ShowMapInfo = 0;
               
            m->img = m->img1;
            // hide enemy and enigm by not blitting them to the screen
             SDL_FreeSurface(m->enm);
             
             //m->pos_enig.x= 9000;
        }
        
        else 
        {
         printf(">>>->> Info is shown");
        	//Show Map Info now
        	*ShowMapInfo = 1;
            m->img = m->img2;
            m->enm=image;
            SDL_Delay(700);   
            
             //m->pos_enm.x = 0;*/

