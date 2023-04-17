#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

typedef struct
{
    char* url;
    SDL_Surface *img,*zoomed;
    SDL_Rect pos_init;
    int rep;
    int tempstart;
    int tempactuel;
    int enigme_state;

}enigme;

typedef struct
{
    SDL_Surface *img;
    SDL_Rect pos_init;
    SDL_Surface *animated[27];

}image;

void generer(enigme * e, char *nomfichier);

void afficherEnigme(enigme e, SDL_Surface * screen);
void zoom(image *i);

int intersection_souris(SDL_Rect poscarre,int mousex,int mousey);

#endif // ENIGME_H_INCLUDED