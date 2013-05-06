#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#define HEIGHT 640
#define WIDTH 640

SDL_Surface *LoadBackGround();
SDL_Surface *CreateTooth();
void DrawTooth();

SDL_Surface *Screen;
SDL_Surface *Tooth;
SDL_Surface *tTooth;
SDL_Surface *Cake;
SDL_Surface *tCake;
SDL_Surface *Candy;
SDL_Surface *tCandy;
SDL_Surface *Burger;
SDL_Surface *tBurger;
SDL_Rect rcBurger;
SDL_Rect rcCandy;
SDL_Rect rcCake;
SDL_Rect rcTooth;
Uint8 *keystate;
int rndm;
int LifesRemaining = 3;


void Init(){

    printf("Initializing video. \n");
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Video Failed %s\n", SDL_GetError() );
    }

    printf("Setting video mode \n");
    Screen = SDL_SetVideoMode(HEIGHT, WIDTH, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

    if(Screen == NULL){
        printf("Unable to set video mode. \n");
        printf("Error located in the Init function in Main \n");
        printf(SDL_GetError());
    }

}
void CreateScreen(){
    SDL_FillRect(Screen, NULL, 0);
    printf("Loading Background");
    LoadBackGround();
    printf("Creating Tooth");

}

void SetTitle(char *name){
        printf("Setting Title %s \n", name);
        SDL_WM_SetCaption(name, NULL);
}

SDL_Surface *LoadBackGround(){
    printf("Loading Background\n");
    char Name[20];
    strcpy(Name, "background.bmp");
    SDL_Surface *Temporary = SDL_LoadBMP(Name);
    SDL_Surface *Image;

    if (Temporary == NULL){
        printf("Unable to read background image %s\n", Temporary);
        return NULL;
    }
   	SDL_SetColorKey(Temporary, (SDL_SRCCOLORKEY|SDL_RLEACCEL), SDL_MapRGB(Temporary->format, 0, 0, 0));
    Image = SDL_DisplayFormat(Temporary);
    SDL_FreeSurface(Temporary);

    SDL_BlitSurface(Image, NULL, Screen, NULL);
    SDL_Flip( Screen);
    SDL_Delay(300);
    SDL_FreeSurface(Image);

    if (Image == NULL){
        printf("Unable to convert image to native format \n");
        return NULL;
    }
    return Image;

}

int Getrndm(){
    int r = rand() % 640;
    return r;
}

int GetrndmMove(){
    int rn = rand() % 20;
    return rn;
}
void DrawCake(){
    Cake = SDL_LoadBMP("cake.bmp");
    // THE CAKE IS A LIE
    tCake = SDL_DisplayFormat(Cake);
    SDL_FreeSurface(Cake);
    rcCake.x = Getrndm();
    rcCake.y = Getrndm();
    rcCake.w = tCake->w;
    rcCake.h = tCake->h;
    SDL_BlitSurface(tCake, NULL, Screen, &rcCake);

}

void MoveBurger(){
    rndm = GetrndmMove();
    printf("The rndm digit is :%d\n", rndm);
    if(rndm > 10 && rndm < 15){
        rcBurger.y -= 1;
    } else if (rndm > 15){
        rcBurger.y -= 0;
    } else if (rndm < 10 && rndm < 5){
        rcBurger.y += 1;
    } else {
        rcBurger.y += 0;
    }

    if(rndm > 10 && rndm < 15){
        rcBurger.x -= 1;
    } else if (rndm > 15){
        rcBurger.x -= 0;
    } else if (rndm < 10 && rndm < 5){
        rcBurger.x += 1;
        rcBurger.x += 0;
    } else {
    }

    if (rcBurger.y == 0){
        rcBurger.y = 5;
    } else if (rcBurger.y >= WIDTH - 20){
        rcBurger.y = WIDTH - 20;
    }
    if (rcBurger.x == 0){
        rcBurger.x = 5;
    } else if (rcBurger.x >= WIDTH - 20){
        rcBurger.x = WIDTH - 20;
    }
    SDL_BlitSurface(tBurger, NULL, Screen, &rcBurger);

}
void MoveCake(){
    rndm = GetrndmMove();
    printf("The rndm digit is :%d\n", rndm);
    if(rndm > 10 && rndm < 15){
        rcCake.x -= 1;
    } else if (rndm > 15){
        rcCake.x -= 0;
    } else if (rndm < 10 && rndm < 5){
        rcCake.x += 1;
    } else {
        rcCake.x += 0;
    }

    if(rndm > 10 && rndm < 15){
        rcCake.y -= 1;
    } else if (rndm > 15){
        rcCake.y -= 0;
    } else if (rndm < 10 && rndm < 5){
        rcCake.y += 1;
    } else {
        rcCake.y += 0;
    }
    //rcCake.x += r1;
    //rcCake.y -= r2;
    if (rcCake.x == 0){
        rcCake.x = 5;
    } else if (rcCake.x >= WIDTH - 20){
        rcCake.x = WIDTH - 20;
    }
    if (rcCake.y == 0){
        rcCake.y = 5;
    } else if (rcCake.y >= WIDTH - 20){
        rcCake.y = WIDTH - 20;
    }
    SDL_BlitSurface(tCake, NULL, Screen, &rcCake);
}

void MoveCandy(){
    rndm = GetrndmMove();
    printf("The rndm digit is :%d\n", rndm);
    if(rndm > 10 && rndm < 15){
        rcCandy.y -= 1;
    } else if (rndm > 15){
        rcCandy.y -= 0;
    } else if (rndm < 10 && rndm < 5){
        rcCandy.y += 1;
    } else {
        rcCandy.y += 0;
    }

    if(rndm > 10 && rndm < 15){
        rcCandy.x -= 1;
    } else if (rndm > 15){
        rcCandy.x -= 0;
    } else if (rndm < 10 && rndm < 5){
        rcCandy.x += 1;
        rcCandy.x += 0;
    } else {
    }

    if (rcCandy.y == 0){
        rcCandy.y = 5;
    } else if (rcCandy.y >= WIDTH - 20){
        rcCandy.y = WIDTH - 20;
    }
    if (rcCandy.x == 0){
        rcCandy.x = 5;
    } else if (rcCandy.x >= WIDTH - 20){
        rcCandy.x = WIDTH - 20;
    }
    SDL_BlitSurface(tCandy, NULL, Screen, &rcCandy);
}

void DrawBurger(){
    Burger = SDL_LoadBMP("burger.bmp");
    tBurger = SDL_DisplayFormat(Burger);
    SDL_FreeSurface(Burger);
    rcBurger.x = Getrndm();
    rcBurger.y = Getrndm();
    rcBurger.h = tBurger->w;
    rcBurger.w = tBurger->h;
    SDL_BlitSurface(tBurger, NULL, Screen, &rcBurger);
}
void DrawCandy(){
    Candy = SDL_LoadBMP("candy.bmp");
    tCandy = SDL_DisplayFormat(Candy);
    SDL_FreeSurface(Candy);
    rcCandy.x = Getrndm();
    rcCandy.y = Getrndm();
    rcCandy.w = tCandy->w;
    rcCandy.h = tCandy->h;
    SDL_BlitSurface(tCandy, NULL, Screen, &rcCandy);
}
void DrawTooth(){
    Tooth = SDL_LoadBMP("tooth.bmp");
    tTooth = SDL_DisplayFormat(Tooth);
    SDL_FreeSurface(Tooth);
    rcTooth.x = 1;
    rcTooth.y = 1;
    rcTooth.w = tTooth->w;
    rcTooth.h = tTooth->h;
    SDL_BlitSurface(tTooth, NULL, Screen, &rcTooth);
}

void GetInput(){

    //printf("Getting input \n");
    SDL_Event Event;

    while(SDL_PollEvent(&Event)){
        switch (Event.type){
            case SDL_QUIT:
                exit(1);
                break;

            case SDL_KEYDOWN:
                switch (Event.key.keysym.sym){
                    case SDLK_UP:
                        rcTooth.y -= 2;
                        printf("Tooth Up\n");
                        break;
                    case SDLK_DOWN:
                        rcTooth.y += 2;
                        printf("Tooth Down\n");
                        break;
                    case SDLK_LEFT:
                        rcTooth.x -= 2;
                        printf("Tooth Left");
                        break;
                    case SDLK_RIGHT:
                        rcTooth.x += 2;
                        printf("Tooth Right\n");
                        break;
                    case SDLK_ESCAPE:
                        exit(1);
                        break;
                    default:
                        break;
                }
                case SDL_KEYUP:
                    switch(Event.key.keysym.sym){
                    case SDLK_UP:
						break;

					case SDLK_DOWN:
						break;

					case SDLK_LEFT:
						break;

					case SDLK_RIGHT:
						break;

					default:
						break;

                    }
                    default:
                        break;
        }
    keystate = SDL_GetKeyState(NULL);
    if (keystate[SDLK_LEFT] ) {
      rcTooth.x -= 2;
    }
    if (keystate[SDLK_RIGHT] ) {
      rcTooth.x += 2;
    }
    if (keystate[SDLK_UP] ) {
      rcTooth.y -= 2;
    }
    if (keystate[SDLK_DOWN] ) {
      rcTooth.y += 2;
    }
    /* collide with edges of screen */
    if ( rcTooth.x < 0 ) {
      rcTooth.x = 0;
    }
    else if ( rcTooth.x > WIDTH-20 ) {
      rcTooth.x = WIDTH-20;
    }
    if ( rcTooth.y < 0 ) {
      rcTooth.y = 0;
    }
    else if ( rcTooth.y > HEIGHT-20 ) {
      rcTooth.y = HEIGHT-20;
    }
    }
    SDL_BlitSurface(tTooth, NULL, Screen, &rcTooth);
    SDL_UpdateRect(Screen, 0, 0, 0, 0);
}
void CheckCollisionCake(){
    if(rcTooth.x == rcCake.x && rcTooth.y == rcCake.y){
    LifesRemaining = LifesRemaining - 1;
    }
}

void CheckCollisionBurger(){
     if(rcTooth.x == rcBurger.x && rcTooth.y == rcBurger.y){
    LifesRemaining = LifesRemaining - 1;
    }
}
void CheckCollisionCandy(){
     if(rcTooth.x == rcCandy.x && rcTooth.y == rcCandy.y){
    LifesRemaining = LifesRemaining - 1;
    }
}
void CheckScore(){
    if(LifesRemaining == 0){
        exit(1);
    }
}
int main(){
    Init();
    SetTitle("Marblecake, also the game");
    CreateScreen();
    DrawTooth();
    DrawCake();
    DrawCandy();
    DrawBurger();
    printf("Entering Loop\n");
    for(;;){
       GetInput();
       MoveCake();
       MoveCandy();
       MoveBurger();
       CheckCollisionCake();
       CheckCollisionBurger();
       CheckCollisionCandy();
       CheckScore();

    }
    return 1;
}
