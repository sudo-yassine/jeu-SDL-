#ifndef test_H 
#define test_H
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h>

typedef struct{

SDL_Rect pos1;
SDL_Rect pos2;

SDL_Surface * img;
SDL_Surface * mask;
}Image;

typedef struct{

SDL_Rect pos1;
SDL_Rect pos2;

SDL_Surface * img;
int SP[8][2];
}Person;
typedef struct{

SDL_Surface * map;
SDL_Rect posmap;

SDL_Surface * dot;
SDL_Rect posdot;


}Map;
void afficher_temps(Uint32 start_time,SDL_Surface*screen);
void init_Background (Image *Backg);
void init_Person (Person *e);
void init_Map (Map *e);
int CheckMouseHover(int xmin,int xmax,int ymin,int ymax);
void afficher_bg(Image p,SDL_Surface *screen);
void afficher_Person(Person p,SDL_Surface *screen);
void afficher_Map(Map m,SDL_Surface *screen);
void liberer(Image A);
void liberer_Person(Person A);
void liberer_Map(Map m);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
void UpdateCoord(Person *p);
int CollisionPP(Person *p,SDL_Surface *o);
int is_same_color(SDL_Color color1, SDL_Color color2);
void afficher_mask(Image p,SDL_Surface *screen);

#endif
