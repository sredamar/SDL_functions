#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#define WINDOW_WIDTH 1000
using namespace std;
void it_horizontalLine(SDL_Renderer *renderer, int x, int y, int len){
    int i;
    if (len != 0) for (i = 0; i < len; i++) SDL_RenderDrawPoint(renderer, x + i, y);}
void it_verticalLine(SDL_Renderer *renderer, int x, int y, int len){
    int i;
    if (len != 0) for ( i = 0; i < len; i++) SDL_RenderDrawPoint(renderer, x, y + i);}
void it_verticalDiagram(SDL_Renderer *render, vector<int>numbers){
    for (int i = 0; i < numbers.size(); i++) it_verticalLine(render, 10 + 10 * i, 500, numbers[i]);}
void it_horizontalDiagram(SDL_Renderer *render, vector<int>numbers){
    for (int i = 0; i < numbers.size(); i++) it_horizontalLine(render, 500, 10 + 10*i, numbers[i]);}
int main(int argc, char* args[]) {
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Init( SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    it_verticalDiagram(renderer, 500, 500 , 100);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    SDL_Delay(3000);
    SDL_Quit();
    return 0;}
