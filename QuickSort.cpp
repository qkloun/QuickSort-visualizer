#include <SDL2/SDL.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int BAR_WIDTH = 5;
const int NUM_BARS = SCREEN_WIDTH / BAR_WIDTH;

void drawBars(SDL_Renderer* renderer, const std::vector<int>& bars, int pivotIndex = -1, int currentIndex = -1) {
    //Sets the bakcground color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    for (int i = 0; i < bars.size(); ++i) {
        if (i == pivotIndex) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue for pivot
        } else if (i == currentIndex) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for current moving bar
        } else {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White for normal bars
        }


        int height = bars[i];
        SDL_Rect barRect = { i * BAR_WIDTH, SCREEN_HEIGHT - height, BAR_WIDTH, height };
        SDL_RenderFillRect(renderer, &barRect);
    }
    SDL_RenderPresent(renderer);
}

void handleSDLEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            SDL_Quit();
            exit(0);
        }
    }
}

int partition(std::vector<int>& bars, int low, int high, SDL_Renderer* renderer) {
    int pivot = bars[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (bars[j] < pivot) {
            ++i;
            std::swap(bars[i], bars[j]);
            drawBars(renderer, bars, high, j); // Visualize with the pivot and current bar
            handleSDLEvents();
            SDL_Delay(50); // Adjust delay to control visualization speed
        }
    }

    std::swap(bars[i + 1], bars[high]);
    drawBars(renderer, bars, high, i + 1); // Visualize with the pivot and current bar
    handleSDLEvents();
    SDL_Delay(10);
    return i + 1;
}

void quicksort(std::vector<int>& bars, int low, int high, SDL_Renderer* renderer) {
    if (low < high) {
        int pi = partition(bars, low, high, renderer);
        quicksort(bars, low, pi - 1, renderer);
        quicksort(bars, pi + 1, high, renderer);
    }
}

int main(int argc, char* args[]) {
    //Error handler in case the programm doesn't work
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Quicksort Visualization", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    std::srand(std::time(0));
    std::vector<int> bars(NUM_BARS);
    for (int i = 0; i < NUM_BARS; ++i) {
        bars[i] = std::rand() % SCREEN_HEIGHT;
    }

    drawBars(renderer, bars);

    quicksort(bars, 0, bars.size() - 1, renderer);

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}