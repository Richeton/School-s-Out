#ifndef _GUI_H            // Prevent multiple definitions if this 
#define _GUI_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include "entity.h"
#include "constants.h"

class GUI_Window
{

protected:
	RECT player_Icon, health_Icon, weapon_Icon, weapon_Ammo;
	const int   player_icon_WIDTH = 64;                // image width
	const int   player_icon_HEIGHT = 64;               // image height
	const int   COLLISION_RADIUS = 120 / 2;   // for circular collision
	const int   player_Icon_x=0; //GAME_WIDTH / 2 - player_icon_WIDTH / 2; // location on screen
	const int   player_Icon_Y=0; //GAME_HEIGHT / 2 - HEIGHT / 2;
	const float MASS = 1.0e14f;         // mass
	const int   TEXTURE_COLS = 2;       // texture has 2 columns
	const int   START_FRAME = 1;        // starts at frame 1
	const int   END_FRAME = 1;          // no animation
public:
	// constructor
	GUI_Window();



};




#endif