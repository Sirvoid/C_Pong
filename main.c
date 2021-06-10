#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>
#include "deltatime.c"

#define WIDTH 250
#define HEIGHT 400
#define ENTITY_NB 3

#include "sprite.c"
#include "entity.c"

int main(int argc, char *argv[])
{
	
	//Init SDL stuff
	SDL_Window *win = NULL;
	SDL_Renderer *renderer = NULL;
	
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	win = SDL_CreateWindow("Pong", 100, 100, WIDTH, HEIGHT, 0);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	
	//Array of game entities
	Entity* entities[ENTITY_NB];
	
	//Player 1
	Entity player1;
	Paddle_Init(renderer, &player1);
	Entity_SetPosition(&player1, WIDTH / 2, HEIGHT - 6);
	entities[0] = &player1;
	
	//Player 2
	Entity player2;
	Paddle_Init(renderer, &player2);
	Entity_SetPosition(&player2, WIDTH / 2, 3);
	entities[1] = &player2;
	
	//Ball
	Entity ball;
	Ball_Init(renderer, &ball);
	Entity_SetPosition(&ball, WIDTH / 2, HEIGHT / 2);
	entities[2] = &ball;
	
	//Game Loop
	while(1) {
		_old_time = currentTimeMs();
		
		//Events
		SDL_Event e;
		if(SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			} else if(e.type == SDL_MOUSEMOTION) {
				Entity_SetPosition(&player1, e.motion.x, player1.y);
			}
		}
			
		//Draw background
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		
		//Update & Draw entities
		Ball_Update(&ball, entities);
		Paddle_DoAI(&player2, &ball);
		for(int i = 0; i < ENTITY_NB; i++) {
			SDL_RenderCopy(renderer, entities[i]->sprite.img, NULL, &entities[i]->sprite.texr);
		}
		
		//Render
		SDL_RenderPresent(renderer);
		
		deltaTime = ((currentTimeMs() - _old_time) + 1) / 1000.0f;
	}
	
	//Free memory
	for(int i = 0; i < ENTITY_NB; i++) {
		Entity_Dispose(entities[i]);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	
	return 0;
}

