#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#define WIDTH 720
#define HEIGHT 720
#define FONT_SIZE 32

SDL_Renderer* renderer;
SDL_Window* window;
TTF_Font* font;
SDL_Color color;
bool running;
int frameCount, timerFPS, lastFrame, fps;

void render();
void input();
void update();

int main(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        std::cout << "Failed at SDL_Init()" << std::endl;
    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) 
        std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;

    TTF_Init();
    font = TTF_OpenFont("Peepo.ttf", FONT_SIZE);

    while(running){
        lastFrame=SDL_GetTicks();
        if(lastFrame >= (lastTime+1000)){
            lastTime = lastFrame;
            fps = frameCount;
            frameCount = 0;
        }
        update();
        input();
        render();
    }
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void render(){
    frameCount++;
    timerFPS = SDL_GetTicks() - lastFrame;
    if(time FPS < (1000/60)) {
        SDL_Delay((1000/60)) - timerFPS;
    }
}

void input(){

}

void update(){

}