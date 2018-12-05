#ifndef _OBSTACLE_H            // Prevent multiple definitions if this 
#define _OBSTACLE_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"

namespace obstacleNS
{
	const int WIDTH = 32;                   // image width
	const int HEIGHT = 32;                  // image height

	const int TEXTURE_COLS = 8;           // texture has 8 columns

	const int OBSTACLE_START_FRAME = 0;      // obstacle starts frame
	const int OBSTACLE_END_FRAME = 0;        // obstacle end frame
	const UINT OBSTACLE_DEFAULT_FRAME = 0;
	const float OBSTACLE_ANIMATION_DELAY = 0.2f;    // obstacle animation frame delay		

	
}

class Obstacle : public Entity
{
private:

public:
	Obstacle();	//Constructor
	~Obstacle();	//Destructor

	void update(float frameTime);
	void collisions();
};

#endif
