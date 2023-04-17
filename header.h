#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED


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


typedef struct{
	char *url;
	SDL_Rect pos_img_affiche;
	SDL_Rect pos_img_ecran; 
	SDL_Surface *img;
}image;


typedef struct {
    SDL_Surface* surface;  
    int x;                 
    int y;                 
    int dx;                
    int dy;                
    int saut;
} personnage;

void initialiser_imageBACK(image *imge);
void afficher_imageBACK(SDL_Surface *screen,image imge);


void init_personnage(personnage* personnage, char* image_path, int x, int y);
void init_personnage2(personnage* personnage, char* image_path, int x, int y);
void afficher_personnage(personnage* personnage, SDL_Surface* screen);
void saut(personnage* personnage);
//void deplacer_personnage1(personnage * personnage, int right, int left, int rightS);
//void deplacer_personnage2(personnage * personnage, int right2, int left2, int rightS);
void deplacement_personnage(personnage* personnage);
//void animate_character(personnage personnage,SDL_Surface** frames, int num_frames, int animation_speed);
//Uint32 animate_timer_callback(Uint32 interval, void* param);

#endif
