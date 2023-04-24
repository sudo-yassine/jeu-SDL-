
#include "background.h"
void initBackground(Background *B)  
{

  B->PositionBg.x = 0;  
  B->PositionBg.y = 0; 
  B->camera.x = 0;  
  B->camera.y = 0;  
  B->camera.w = 1500;  
  B->camera.h = 700;  

  B->frame = 1;  

  char string[20];  
  int i;  

  for (i = 1; i <=8; i++)  
  {
    sprintf(string, "background/b%d.png", i); 
    B->BgImg[i] = IMG_Load(string);  
  }

  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);  
  B->music = Mix_LoadMUS("music.mp3");  
  Mix_PlayMusic(B->music, -1); 

  B->vies = IMG_Load("HEARTS.png");  
  B->posVie1.x = 0;  
  B->posVie1.y = 0;  
  B->posVie1.w = 84; 
  B->posVie1.h = 213;  
  B->vie = 100;  

  B->posVie2.x = 749;  
  B->posVie2.y = 26;  
  B->posVie2.w = 84;  
  B->posVie2.h = 213;  

  TTF_Init();  
  B->police = TTF_OpenFont("font/font.ttf", 40);  

  B->score = 1000;  
  B->posScore.x = 0;  
  B->posScore.y = 250;  
}

void affBackground(Background *B, SDL_Surface *screen)
{
 
  SDL_BlitSurface(B->BgImg[B->frame], &(B->camera), screen, &(B->PositionBg));

 
  SDL_BlitSurface(B->vies, &(B->posVie2), screen, &(B->posVie1));

  
  if (B->vie >= 100)
  {
    B->posVie2.x = 749;
    B->posVie2.y = 26;
    B->posVie2.w = 84;
    B->posVie2.h = 213;
  }
  if (B->vie >= 85 && B->vie < 100)
  {
    B->posVie2.x = 633;
    B->posVie2.y = 26;
    B->posVie2.w = 84;
    B->posVie2.h = 213;
  }
  if (B->vie >= 75 && B->vie < 85)
  {
    B->posVie2.x = 516;
    B->posVie2.y = 26;
    B->posVie2.w = 84;
    B->posVie2.h = 213;
  }
  if (B->vie >= 50 && B->vie < 75)
  {
    B->posVie2.x = 402 ;
    B->posVie2.y = 26;
    B->posVie2.w = 84;
    B->posVie2.h = 213;
  }
  if (B->vie >= 25 && B->vie < 50)
  {
    B->posVie2.x = 172;
    B->posVie2.y = 39;
    B->posVie2.w = 87;
    B->posVie2.h = 208;
  }
  if (B->vie >= 0 && B->vie < 25)
  {
    B->posVie2.x = 59;
    B->posVie2.y = 39;
    B->posVie2.w = 87;
    B->posVie2.h = 208;
  }

  
  SDL_Color couleur = {0, 0, 0};

 
  char s[20];
  sprintf(s, "Score: %d", B->score);

  
  B->scores = TTF_RenderText_Blended(B->police, s, couleur);

  
  SDL_BlitSurface(B->scores, NULL, screen, &(B->posScore));
}


void animerBack(Background *B)
{
 
  if (B->frame == 7)
    B->frame = 0;

  
  B->frame++;
}


void scrolling(Background *B, SDL_Rect posPerso, int direction)
{
  const int speed = 20;
  if (direction == 1)
  {
    if (( B->camera.x <10000 - B->camera.w)  &&(posPerso.x >= 750))
    {
      B->camera.x += speed;
      posPerso.y +=200;
    }
  }
  else if (direction == 0)
  {
    if (B->camera.x > 0)
    {
      B->camera.x -= speed;
      posPerso.y +=200;
    }
  }
}
void freeBackground(Background *B)
{
  for (int i = 0; i < 8; i++)
  {
    SDL_FreeSurface(B->BgImg[i]);
  }
  
  SDL_FreeSurface(B->vies);
  SDL_FreeSurface(B->scores);
  Mix_FreeMusic(B->music);
}

void sauvegarder(ScoreInfo s, char *file)
{
  FILE *f = fopen(file, "w+");
  fprintf(f, "%s %d %d \n", s.name, s.score, s.time);
  fclose(f);
}

void bestScore(ScoreInfo s[], int n, char *file)
{
  int max1 = 0;
  int i;
  for (i = 0; i < n; i++)
  {
    if (s[i].score > max1)
      max1 = s[i].score;
  }

  int max2 = 0;
  for (i = 0; i < n; i++)
  {
    if ((s[i].score > max2) && (s[i].score != max1))
      max2 = s[i].score;
  }

  int max3 = 0;
  for (i = 0; i < n; i++)
  {
    if ((s[i].score > max3) && (s[i].score != max1) && (s[i].score != max2))
      max3 = s[i].score;
  }
}
