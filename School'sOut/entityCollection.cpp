#include "entityCollection.h"
#include <algorithm>
#include "enemy.h"

// adds an entity into the entityCollection list
bool EntityCollection::addEntity(Entity* en)
{
	entityCollection.push_back(en);
	return true;
}

// deletes an entity from the entityCollection list by entity's name
bool EntityCollection::deleteEntity(Entity* en)
{
	// create iterator here
	int i = 0;
	for (const auto entity : entityCollection)
	{
		i++;
		// put iterator here
		if (&en == &entity)
		{

			entityCollection.erase(entityCollection.begin() + i);
			return true;
		}
	}

	return false; // entity not found
}


// deletes an entity from the entityCollection list by entity's index
bool EntityCollection::deleteEntity(int i)
{
	return true;
}



// gets an entity from the entityCollection list using the entity's index
Entity EntityCollection::getEntity(int i)
{
	Entity e;
	return e;
}

// update for all entities
bool EntityCollection::entityUpdate(float frameTime)
{
	for (const auto entity : entityCollection)
	{
		entity->update(frameTime);
	}
	return true;
}


// ai for all entities
bool EntityCollection::entityAI(float frameTime, Entity* en)
{
	for (const auto entity : entityCollection)
	{
		entity->ai(frameTime, *en);
	}
	return true;
}

// collision for all entities
bool EntityCollection::entityCollision(Entity en)
{
	for (const auto entity : entityCollection)
	{
		// Handle collisions
	}
	return true;
}

// render for all entities
bool EntityCollection::entityRender()
{
	for (const auto entity : entityCollection)
	{
		entity->draw();
	}
	return true;
}
