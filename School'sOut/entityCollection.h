#ifndef _ENTITYCOLLECTION_H
#define _ENTITYCOLLECTION_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include <list>
#include "player.h"


class EntityCollection 
{
private:

	std::list<Entity> entityCollection;

public:

	bool addEntity(Entity en);

	bool deleteEntity(Entity en);

	bool deleteEntity(int i);

	Entity getEntity(int i);

};


#endif // _entityCollection_H
