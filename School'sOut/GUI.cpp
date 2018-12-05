#include "GUI.h"

//=============================================================================
// default constructor
//=============================================================================
GUI_Window::GUI_Window()
{
	player_Icon.left = 0;
	player_Icon.top = 0;

	player_Icon.right = GAME_WIDTH / 8;
	player_Icon.bottom = GAME_HEIGHT / 6;

	health_Icon.left = GAME_WIDTH / 7;
	health_Icon.top = 0;

	health_Icon.right = GAME_WIDTH / 5;
	health_Icon.bottom = GAME_HEIGHT / 12;

	healthText = "5/7";

}

GUI_Window::~GUI_Window()
{

}


RECT GUI_Window::returnPlayer() 
{
	return player_Icon; 
}

std::string GUI_Window::returnHealth() 
{
	return healthText;
}

void GUI_Window::update(Player player)

{
	int newHealth = int(player.getHealth());
	std::string updateHealth = std::to_string(newHealth);
	healthText = updateHealth;
}


/*void GUI_Window::update()
{

int newHealth = 10;
std::string updateHealth = std::to_string(newHealth);
healthText = updateHealth;

}
*/