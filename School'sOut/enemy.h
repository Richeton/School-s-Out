#ifndef _ENEMY_H
#define _ENEMY_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"

namespace enemyNS
{
	const int WIDTH = 32;                   // image width
	const int HEIGHT = 32;                  // image height
											//const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
											//const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
											//const float SPEED = 100;                // 100 pixels per second
	const int   TEXTURE_COLS = 8;           // texture has 8 columns
											//const int   ENEMY_START_FRAME = 0;      // enemy starts at frame 0
											//const int   ENEMY_END_FRAME = 0;        // enemy animation frames 0,1,2,3
											//const float ENEMY_ANIMATION_DELAY = 0.2f;    // time between frames	
}

class Enemy : public Entity
{
private:
public:
	Enemy();	//Constructor
	~Enemy();	//Destructor

	void update(float frameTime);

	void ai(float frameTime, Entity &ent);
	//void goTo(float x, float y);

};

#endif