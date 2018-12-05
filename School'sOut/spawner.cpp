#include <random>
#include "spawner.h"

Spawner::Spawner()
{
}


Spawner::~Spawner()
{
}

bool Spawner::enemySpawn(EntityCollection* entityCollection, Player* player, Game& gamePtr, TextureManager& gameTexture, float frameTime)
{
	if (entityCollection->getEnemyCollection().size() < 5)// enemySpawnNS::ENEMY_CAP)
	{
		enemyTimer -= frameTime;
		if (enemyTimer <= 0)
		{
			enemyTimer = 2;
			float randPosX = rand() % (GAME_BOUNDARY_XEND - GAME_BOUNDARY_XSTART - enemyNS::WIDTH) + GAME_BOUNDARY_XSTART;
			float randPosY = rand() % (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART - enemyNS::HEIGHT) + GAME_BOUNDARY_YSTART;

			float edgeLeft = player->getX() - 100;
			float edgeRight = player->getX() + 100;
			float edgeUp = player->getY() - 100;
			float edgeDown = player->getY() + 100;

			while (true)
			{
				if (!(edgeLeft > randPosX || edgeRight < randPosX || edgeUp > randPosY || edgeDown < randPosY))
				{
					randPosX = rand() % (GAME_BOUNDARY_XEND - GAME_BOUNDARY_XSTART - enemyNS::WIDTH) + GAME_BOUNDARY_XSTART;
					randPosY = rand() % (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART - enemyNS::HEIGHT) + GAME_BOUNDARY_YSTART;
					continue;
				}
				break;
			}



			Enemy* newEnemy = new Enemy();
			if (!newEnemy->initialize(&gamePtr, enemyNS::WIDTH, enemyNS::HEIGHT, enemyNS::TEXTURE_COLS, &gameTexture))
				throw(GameError(gameErrorNS::FATAL_ERROR,
					"Error initializing enemy"));
			newEnemy->setEdge(-8, 8, -15, 15);
			newEnemy->setX(randPosX);
			newEnemy->setY(randPosY);
			entityCollection->add(newEnemy);

			return true;
		}
	}
	return true;
}


bool Spawner::obstacleSpawn(EntityCollection* entityCollection, Player* player, Game& gamePtr, TextureManager& gameTexture, float frameTime)
{	
	if (entityCollection->getObstacleCollection().size() < 5)// 
	{
		obstacleTimer -= frameTime;
		if (obstacleTimer <= 0)
		{
			obstacleTimer = 2;
			float randPosX = rand() % (GAME_BOUNDARY_XEND - GAME_BOUNDARY_XSTART - obstacleNS::WIDTH) + GAME_BOUNDARY_XSTART;
			float randPosY = rand() % (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART - obstacleNS::HEIGHT) + GAME_BOUNDARY_YSTART;

			float edgeLeft = player->getX() - 100;
			float edgeRight = player->getX() + 100;
			float edgeUp = player->getY() - 100;
			float edgeDown = player->getY() + 100;

			while (true)
			{
				if (!(edgeLeft > randPosX || edgeRight < randPosX || edgeUp > randPosY || edgeDown < randPosY))
				{
					randPosX = rand() % (GAME_BOUNDARY_XEND - GAME_BOUNDARY_XSTART - obstacleNS::WIDTH) + GAME_BOUNDARY_XSTART;
					randPosY = rand() % (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART - obstacleNS::HEIGHT) + GAME_BOUNDARY_YSTART;
					continue;
				}
				break;
			}



			Obstacle* newObstacle = new Obstacle();
			if (!newObstacle->initialize(&gamePtr, obstacleNS::WIDTH, obstacleNS::HEIGHT, obstacleNS::TEXTURE_COLS, &gameTexture))
				throw(GameError(gameErrorNS::FATAL_ERROR,
					"Error initializing obstacle"));
			newObstacle->setEdge(-8, 8, -15, 15);
			newObstacle->setX(randPosX);
			newObstacle->setY(randPosY);
			entityCollection->add(newObstacle);

			return true;
		}
	}
	return true;
}