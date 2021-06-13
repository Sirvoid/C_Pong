#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "sprite.h"

void Sprite_LoadImage(SDL_Renderer *renderer, Sprite *sprite, char imgPath[]) {
	int w, h;
	
	SDL_Surface* temp = IMG_Load(imgPath);
	if(temp == NULL) {
		printf("Couldn't find image %s", imgPath);
	}
	
	sprite->img = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_QueryTexture(sprite->img, NULL, NULL, &w, &h);
	SDL_FreeSurface(temp);
	
	sprite->texr.x = 0;
	sprite->texr.y = 0;
	sprite->texr.w = w*2;
	sprite->texr.h = h*2;
}

void Sprite_SetPosition(Sprite *sprite, int x, int y) {
	sprite->texr.x = x;
	sprite->texr.y = y;
}

void Sprite_Dispose(Sprite *sprite) {
	SDL_DestroyTexture(sprite->img);
}
