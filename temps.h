#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>

typedef struct temps
{
SDL_Surface *texte;

SDL_Rect position;
  
    TTF_Font *police ;

 char entree[100]; 

 int secondesEcoulees; 

SDL_Color couleurBlanche;
time_t t1,t2; 
int min, sec;
}temps;

void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);
void free_temps(temps *t,SDL_Surface *ecran);
