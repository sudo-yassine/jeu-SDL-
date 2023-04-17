#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"


void generer(enigme *e, char *nomfichier)
{
            char url[256];
            int num_rep;
        FILE* f=NULL;
        f=fopen(nomfichier,"r+");
        if(f == NULL)
        {
            printf("unable open  file");
        }
        else
        {

            fscanf(f,"path: %s num_reponse: %d",url,&num_rep);
            e->rep=num_rep;
            printf("num rep %d",e->rep);
            e->img=IMG_Load(url);
            if(e->img==NULL)
            printf("error load img");

            e->tempstart=SDL_GetTicks();
            e->enigme_state=0;

        }
        
}
void afficherEnigme(enigme e, SDL_Surface * screen)
{
    SDL_BlitSurface(e.img,NULL,screen,NULL);
}



int intersection_souris(SDL_Rect poscarre,int mousex,int mousey)
{
	if((mousex>poscarre.x && mousex < poscarre.x+poscarre.w) && (mousey>poscarre.y && mousey<poscarre.y+poscarre.h) )
	{
		return 1;
	}
	else 
    {
    return 0;
    }
}

