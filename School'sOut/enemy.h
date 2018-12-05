#ifndef _ENEMY_H            // Prevent multiple definitions if this 
#define _ENEMY_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "state.h"

namespace enemyNS
{
	const int WIDTH = 32;                   // image width
	const int HEIGHT = 32;                  // image height

	const int   TEXTURE_COLS = 8;           // texture has 8 columns

	const int ALERT_DIST = 300;
	const int BASE_SPEED = 75;

	const UINT ENEMY_DEFAULT_FRAME = 17;
}

class Enemy : public Entity
{
private:
	State * aiState;
public:
	Enemy();	//Constructor
	~Enemy();	//Destructor

	void update(float frameTime);

	void ai(float frameTime, Entity &ent);	// Execute the AI
	void setAI(State * aiState);
	State* getAI();

};

#endif
