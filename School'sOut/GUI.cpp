#include "gui.h"

//=============================================================================
// default constructor
//=============================================================================
GUI_Window::GUI_Window()
{
	// Position to be tweaked
	player_Icon.left = 0;
	player_Icon.top = 0;

	player_Icon.right = GAME_WIDTH / 8;
	player_Icon.bottom = GAME_HEIGHT / 8;


	health_Icon.left = GAME_WIDTH / 7;
	health_Icon.top = 0;

	health_Icon.right = GAME_WIDTH / 5;
	health_Icon.bottom = GAME_HEIGHT / 12;

}




