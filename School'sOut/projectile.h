#ifndef _PROJECTILE_H               // Prevent multiple definitions if this 
#define _PROJECTILE_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h";

class Projectile : public Entity
{
	int quantity;	// number of projectile
	int damage;		// damage of the projectile
	float speed;	// projectile speed (pixels traveled per second)
};

#endif