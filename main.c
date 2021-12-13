#include<stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include<time.h>
#include <SDL/SDL_ttf.h>
#include "fonctio.h"

int main(int argc, char *argv[]){
int continuer=1;
cordo z;
SDL_Surface *ecran = NULL,*image=NULL;
SDL_Rect pos;
SDL_Event event;

SDL_Init(SDL_INIT_VIDEO);
ecran = SDL_SetVideoMode(330+430,630, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_WM_SetIcon(SDL_LoadBMP("file/images/others/8.bmp"),NULL);
SDL_WM_SetCaption("block puzzle", NULL);
image=SDL_LoadBMP("file/images/others/Menu.bmp");
pos.x=0;pos.y=0;
SDL_BlitSurface(image, NULL, ecran, &pos);
SDL_Flip(ecran);

while(continuer){
    SDL_PollEvent(&event);
        switch(event.type){
            case SDL_QUIT:continuer=0;
            case SDL_MOUSEBUTTONDOWN:
                z.x=event.button.x;
                z.y=event.button.y;
                if(z.x > 50 && z.y >320 && z.x <260 && z.y <405){
                    jeux(1);
                    ecran = SDL_SetVideoMode(760,630, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
                       SDL_BlitSurface(image, NULL, ecran, &pos);
                        SDL_Flip(ecran);
                }
                if(z.x > 270 && z.y >202 && z.x <480 && z.y <288){
                    pc();
                    ecran = SDL_SetVideoMode(760,630, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
                    SDL_BlitSurface(image, NULL, ecran, &pos);
                        SDL_Flip(ecran);
                }
                if(z.x > 495 && z.y >320 && z.x <705 && z.y <405){
                    jeux(3);
                       ecran = SDL_SetVideoMode(760,630, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
                       SDL_BlitSurface(image, NULL, ecran, &pos);
                        SDL_Flip(ecran);
                }
                if(z.x > 710 && z.y >3 && z.x <758 && z.y <73){
                continuer=0;
                }
                if(z.x > 0 && z.y >0 && z.x <22 && z.y <38){
                help(ecran);
                 ecran = SDL_SetVideoMode(760,630, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
                SDL_BlitSurface(image, NULL, ecran, &pos);
                SDL_Flip(ecran);
                }
                if(z.x > 340 && z.y >467 && z.x <420 && z.y <555){
                    topscoremain2(ecran);
                    ecran = SDL_SetVideoMode(760,630, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
                    SDL_BlitSurface(image, NULL, ecran, &pos);
                    SDL_Flip(ecran);
                SDL_Flip(ecran);                }
                break;
                          }
}
SDL_Quit();
return EXIT_SUCCESS;
}
