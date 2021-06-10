#include "paddle.h"

void Paddle_Init(SDL_Renderer* renderer, Entity* entity) {
	Sprite_LoadImage(renderer, &entity->sprite, "images/paddle.png");
	entity->type = 0;
	entity->vely = 0;
	entity->velx = 0;
}

void Paddle_DoAI(Entity* paddle, Entity* ball) {
	float paddleMidX = paddle->x + paddle->sprite.texr.w / 2;
	
	paddle->velx = (ball->x - paddleMidX) * 4;
	
	Entity_Update(paddle);
}
