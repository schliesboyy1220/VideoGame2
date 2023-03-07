#incldue <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Circle Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Set initial position of the circle
    int circle_x = SCREEN_WIDTH / 2;
    int circle_y = SCREEN_HEIGHT / 2;

    // Set initial velocity of the circle
    int circle_vel_x = 0;
    int circle_vel_y = 0;

    // Game loop
    bool quit = false;
    while (!quit)
    {
        // Handle events
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            // Handle quit event
            if (e.type == SDL_QUIT)
            {
                quit = true;
		else if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
		{
		// Move circle up
		case SDLK_UP:
		    circle_vel_y = -5;
		    break;

                // Move circle down
                case SDLK_DOWN:
                    circle_vel_y = 5;
                    break;

                // Move circle left
                case SDLK_LEFT:
                    circle_vel_x = -5;
                    break;

                // Move circle right
                case SDLK_RIGHT:
                    circle_vel_x = 5;
                    break;

                // Handle other key events
                default:
                    break;
            }
        }
        else if (e.type == SDL_KEYUP)
        {
            switch (e.key.keysym.sym)
            {
                // Stop moving circle up
                case SDLK_UP:
                    circle_vel_y = 0;
                    break;

                // Stop moving circle down
                case SDLK_DOWN:
                    circle_vel_y = 0;
                    break;

                // Stop moving circle left
                case SDLK_LEFT:
                    circle_vel_x = 0;
                    break;

                // Stop moving circle right
                case SDLK_RIGHT:
                    circle_vel_x = 0;
                    break;

                // Handle other key events
                default:
                    break;
            }
        }
    }

    // Update circle position
    circle_x += circle_vel_x;
    circle_y += circle_vel_y;

    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw circle
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, circle_x, circle_y);

    // Update screen
    SDL_RenderPresent(renderer);
}

// Destroy renderer
SDL_DestroyRenderer(renderer);

// Destroy window
SDL_DestroyWindow(window);

// Quit SDL
SDL_Quit();

return 0;
}
