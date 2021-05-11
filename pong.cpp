#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#define WIDTH 720
#define HEIGHT 720
#define FONT_SIZE 32
#define BALL_SPEED 16
#define SPEED 9
#define SIZE 16

SDL_Renderer* renderer;
SDL_Window* window;
TTF_Font* font;
SDL_Color color;
bool running;
int frameCount, timerFPS, lastFrame, fps;

SDL_Rect left_pad, right_pad, ball, score_board;
float velX, velY;
std::string score;
int left_score;
int right_score;
bool turn;

void serve(){
    left_pad.y = (HEIGHT/2) - (left_pad.h/2);
    right_pad.y = (HEIGHT/2) - (left_pad.h/2);
    if(turn){
        ball.x = left_pad.x + (left_pad.w * 4);
    }else{
        ball.x = right_pad.x - (right_pad.w * 4);
    }
    velX = BALL_SPEED/2;
    velY = 0;
    ball.y = HEIGHT/2-(SIZE/2);
    turn = !turn;
}

void write(std::string text, int x, int y){
    SDL_Surface *surface;
    SDL_Texture *texture;
    const char* t = text.c_str();
    surface = TTF_RenderText_Solid(font, t, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    score_board.w = surface -> w;
    score_board.h = surface -> h;
    score_board.x = x - score_board.w;
    score_board.y = y - score_board.h;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, &score_board);


}

void update(){}

void input(){
    SDL_Event e;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&e)) {
        if(e.type==SDL_QUIT)
            running = false;
    }
        if(keystates[SDL_SCANCODE_ESCAPE])
            running = false;
        if(keystates[SDL_SCANCODE_UP]) ;
            
        if(keystates[SDL_SCANCODE_UP]) ;

}

void render(){
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(renderer);

    frameCount++;
    timerFPS = SDL_GetTicks() - lastFrame;
    if(timerFPS < (1000/60)) {
        SDL_Delay((1000/60) - timerFPS);
    }

    write(score, WIDTH/2+FONT_SIZE, FONT_SIZE*2);

    




    SDL_RenderPresent(renderer);
}


int main(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        std::cout << "Failed at SDL_Init()" << std::endl;
    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) 
        std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;

    TTF_Init();
    font = TTF_OpenFont("Peepo.ttf", FONT_SIZE);

    color.r = 255;
    color.g = 255;
    color.b = 255;

    left_score = 0;
    right_score = 0;
    left_pad.x = 32; left_pad.h=HEIGHT/4;
    right_pad = left_pad;
    right_pad.x = WIDTH - right_pad.w - 32;
    ball.w = SIZE;
    ball.h = SIZE;

    serve();

    running = 1;
    static int lastTime = 0;
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