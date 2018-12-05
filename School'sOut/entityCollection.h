#ifndef _ENTITYCOLLECTION_H
#define _ENTITYCOLLECTION_H
#define WIN32_LEAN_AND_MEAN

#include <vector>
#include "entity.h"
#include "player.h"
#include "obstacle.h"
#include "enemy.h"
#include "projectile.h"

// Store and Execute Functions on Entities
class EntityCollection
{
private:
	Player* playerPtr;
	std::vector<Entity*> entityCollection;
	std::vector<Enemy*> enemyCollection;
	std::vector<Obstacle*> obstacleCollection;
	std::vector<Projectile*> projCollection;

public:
	bool add(Entity* entity);
	bool add(Enemy* enemy);
	bool add(Obstacle* projectile);
	bool add(Projectile* projectile);
	

	bool remove(Entity* entity);
	bool remove(Enemy* enemy);
	bool remove(Obstacle* obstacle);
	bool remove(Projectile* projectile);
	//bool remove(int i);

	Entity* get(int i);
	Enemy* getEnemy(int i);
	
	std::vector<Enemy*> getEnemyCollection();

	Obstacle* getObstacle(int i);
	std::vector<Obstacle*> getObstacleCollection();

	Projectile* getProjectile(int i);

	bool update(float frameTime);
	bool ai(float frameTime, Entity * en);
	bool collision();
	bool render();

	//void enemyPlayerCollision(Player* player, float frameTime);
};


#endif // _entityCollection_H
