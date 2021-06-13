#ifndef G_BALL_H
#define G_BALL_H

#include <SDL2/SDL.h>
#include "entity.h"

void Ball_Init(SDL_Renderer *renderer, Entity *entity);
void Ball_Update(Entity *ball, Entity *entities[]);
void Ball_Respawn(Entity *ball);

#endif
