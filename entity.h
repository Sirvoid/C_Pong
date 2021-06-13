#ifndef G_ENTITY_H
#define G_ENTITY_H

#include "sprite.h"

typedef struct {
	Sprite sprite;
	int type;
	float x;
	float y;
	float velx; //In pixels per seconds
	float vely; //In pixels per seconds
} Entity;

void Entity_SetPosition(Entity *entity, float x, float y);
void Entity_SetVelocity(Entity *entity, float velx, float vely);
void Entity_MoveX(Entity *entity, float speed);
void Entity_MoveY(Entity *entity, float speed);
void Entity_Update(Entity *entity);
void Entity_Dispose(Entity *entity);

int Entity_TestCollision(Entity *entity, Entity *entity2);

#endif
