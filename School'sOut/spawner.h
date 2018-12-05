#ifndef _SPAWNER_H
#define _SPAWNER_H
#define WIN32_LEAN_AND_MEAN

#include "entityCollection.h"
#include "player.h"
#include <vector>

class Spawner
{
private:
	float enemyTimer = 0.0f;
	float obstacleTimer = 0.0f;

public:
	Spawner();
	~Spawner();
	bool enemySpawn(EntityCollection* entityCollection, Player* player, Game& gamePtr, TextureManager& gameTexture, float frameTime);		// returns true if works
	bool obstacleSpawn(EntityCollection* entityCollection, Player* player, Game& gamePtr, TextureManager& gameTexture, float frameTime);
	
};

#endif