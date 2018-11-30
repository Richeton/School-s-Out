#ifndef _ENTITYCOLLECTION_H
#define _ENTITYCOLLECTION_H
#define WIN32_LEAN_AND_MEAN


#include "entity.h"
#include <vector>
#include "player.h"


class EntityCollection
{
private:

	std::vector<Entity*> entityCollection;

public:

	bool addEntity(Entity* en);

	bool deleteEntity(Entity* en);

	bool deleteEntity(int i);

	Entity getEntity(int i);

	bool entityUpdate(float frameTime);
	bool entityAI(float frameTime, Entity * en);
	bool entityCollision(Entity en);
	bool entityRender();
};


#endif // _entityCollection_H
