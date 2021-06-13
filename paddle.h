#ifndef G_PADDLE_H
#define G_PADDLE_H

#include <SDL2/SDL.h>
#include "entity.h"

void Paddle_Init(SDL_Renderer *renderer, Entity *entity);
void Paddle_DoAI(Entity *paddle, Entity *ball);

#endif
