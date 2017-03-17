
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character,*character3,*ch2;
SDL_Rect rect_background,rect_character,rect_character3,r_ch2;
int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }
    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.jpg");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = 600;
    rect_background.h = 300;
    ch2 = IMG_LoadTexture(renderer,"pipe.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    r_ch2.x = 200;
    r_ch2.y = 150;
    r_ch2.w = 60;
    r_ch2.h = 150;
    character = IMG_LoadTexture(renderer, "personaje.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = 100;
    rect_character.h = 150;
    character3 = IMG_LoadTexture(renderer, "yoshi.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character3.x = 300;
    rect_character3.y = 100;
    rect_character3.w = 170;
    rect_character3.h = 170;
    character3 = IMG_LoadTexture(renderer, "pastilla.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character3.x = 300;
    rect_character3.y = 0;
    rect_character3.w = 170;
    rect_character3.h = 70;
    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_character.x++;
            }
        }
        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);
        SDL_RenderCopy(renderer, character3, NULL, &rect_character3);
        SDL_RenderCopy(renderer, ch2, NULL, &r_ch2);
        SDL_RenderPresent(renderer);
    }
	return 0;
}
