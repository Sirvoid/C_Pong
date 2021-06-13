#include "sprite.h"
#include "entity.h"
#include "ball.h"
#include "paddle.h"
#include "deltatime.h"

void Entity_SetPosition(Entity *entity, float x, float y) {
	entity->x = x;
	entity->y = y;
	Sprite_SetPosition(&entity->sprite, x, y);
}

void Entity_SetVelocity(Entity *entity, float velx, float vely) {
	entity->velx = velx;
	entity->vely = vely;
}

void Entity_MoveX(Entity *entity, float speed) {
	Entity_SetPosition(entity, entity->x + speed, entity->y);
}

void Entity_MoveY(Entity *entity, float speed) {
	Entity_SetPosition(entity, entity->x, entity->y + speed);
}

void Entity_Update(Entity *entity) {
	Entity_MoveX(entity, entity->velx * deltaTime);
	Entity_MoveY(entity, entity->vely * deltaTime);
}

int Entity_TestCollision(Entity *entity, Entity *entity2) {
	
	int eX = entity->x;
	int eX2 = eX + entity->sprite.texr.w;
	int eY = entity->y;
	int eY2 = eY + entity->sprite.texr.h;
	
	int e2X = entity2->x;
	int e2X2 = e2X + entity2->sprite.texr.w;
	int e2Y = entity2->y;
	int e2Y2 = e2Y + entity2->sprite.texr.h;
	
	if (eX2 > e2X && 
		eX < e2X2 && 
		eY2 > e2Y && 
		eY < e2Y2) {
		return 1;
	}
	
	return 0;
}

void Entity_Dispose(Entity *entity) {
	Sprite_Dispose(&entity->sprite);
}
