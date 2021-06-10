#include "ball.h"

void Ball_Init(SDL_Renderer* renderer, Entity* entity) {
	Sprite_LoadImage(renderer, &entity->sprite, "images/ball.png");
	entity->type = 1;
	entity->velx = 0;
	Ball_Respawn(entity);
}

void Ball_Update(Entity* ball, Entity* entities[]) {
	
	for(int i = 0; i < 2; i++) {
		if(Entity_TestCollision(ball, entities[i])) {
			
			float bX = ball->x;
			float bY = ball->y;
			float pX = entities[i]->x;
			float pY = entities[i]->y;
			float pW = entities[i]->sprite.texr.w;
			
			float a = ((pX + pW - bX) / pW) * M_PI;
			a += M_PI;
			
			ball->vely = sin(a) * 100;
			ball->velx = -cos(a) * 100;
			
			if(bY > pY) {
				ball->vely = -ball->vely;
			}
			
			break;
		}
	}
	
	//Bounce on sides
	if(ball->x >= WIDTH || ball->x <= 0) {
		ball->velx = -ball->velx;
	}
	
	//Respawn reaching bottom or top
	if(ball->y >= HEIGHT || ball->y <= 0) {
		Ball_Respawn(ball);
	}
	
	Entity_Update(ball);
}

void Ball_Respawn(Entity* ball) {
	ball->y = HEIGHT / 2;
	ball->x = WIDTH / 2;
	
	if(rand() % 2 == 0) {
		ball->vely = 100.0f;
	} else {
		ball->vely = -100.0f;
	}
}
