#include "entityCollection.h"
#include <algorithm>

// adds an entity into the entityCollection list
bool EntityCollection::addEntity(Entity en)
{
	entityCollection.push_back(en);
	return true;
}

//// deletes an entity from the entityCollection list by entity's name
//bool EntityCollection::deleteEntity(Entity en)
//{
//	entityCollection.remove(en);
//}

/*
// deletes an entity from the entityCollection list by entity's index
bool EntityCollection::deleteEntity(int i)
{
	//for_each(entityCollection.begin(), entityCollection.end(), (This Function is what is done in the loop))
}

*/


// gets an entity from the entityCollection list using the entity's index
Entity EntityCollection::getEntity(int i)
{
	Entity e;
	return e;
}