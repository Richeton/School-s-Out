// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Draw animated spaceships with collision and shield
// Chapter 6 SchoolsOut.cpp v1.0
// This class is the core of the game

#include "schoolsOut.h"

//=============================================================================
// Constructor
//=============================================================================
SchoolsOut::SchoolsOut()
{
	guiwin = new GUI_Window();
}

//=============================================================================
// Destructor
//=============================================================================
SchoolsOut::~SchoolsOut()
{
	SAFE_DELETE(guiwin);
	releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void SchoolsOut::initialize(HWND hwnd)
{
	Game::initialize(hwnd); // throws GameError

							// stage texture
	if (!stageTexture.initialize(graphics, STAGE_BACKGROUND))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing stage texture"));

	// main game textures
	if (!gameTexture.initialize(graphics, TEXTURES_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing game texture"));


	// background
	if (!background.initialize(graphics, GAME_WIDTH, GAME_HEIGHT, 0, &stageTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing background"));


	// player
	if (!player->initialize(this, playerNS::WIDTH, playerNS::HEIGHT, playerNS::TEXTURE_COLS, &gameTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing player"));

	entityCollection.add(player);


	player->setEdge(-8, 8, -15, 15);

	
	// Set player position to a center of the game boundaries
	player->setX(GAME_BOUNDARY_XSTART + (GAME_BOUNDARY_XEND - GAME_BOUNDARY_XSTART) / 2);
	player->setY(GAME_BOUNDARY_YSTART + (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART) / 2);

	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void SchoolsOut::update()
{	
	spawner.enemySpawn(&entityCollection, player, *this, gameTexture, frameTime);
	spawner.obstacleSpawn(&entityCollection, player, *this, gameTexture, frameTime);
	entityCollection.update(frameTime);
	guiwin->update(*player);

}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void SchoolsOut::ai()
{
	// enemies ai follows player
	entityCollection.ai(frameTime, player);
//	
	// enemyAI(frameTime, player);
	//	entityCollection.entityAI(frameTime, player);
	

}

//=============================================================================
// Handle collisions
//=============================================================================
void SchoolsOut::collisions()
{
	D3DXVECTOR2 colVect;
	//enemySpawn.enemyCollision(player, frameTime);
	/*WILSON'S GARBAGE
	D3DXVsdECTOR2 colVect;
	if (enemy1.collidesWith(player, colVect))
	{
		if (player.getHealth() > 0)
		{
			//float currentHealth = player.getHealth()
			player.setHealth(player.getHealth() - 1);
		}

		else if (player.getHealth() <= 0)
		{
			game_state = 2;

			//throw(GameError(gameErrorNS::FATAL_ERROR, "You ded"));
			//SAFE_DELETE(guiwin);
		}
	}

	*/

	/*
	D3DXVECTOR2 colVect;
	if (enemy1->collidesWith(player, colVect))
	{
	throw(GameError(gameErrorNS::FATAL_ERROR,
	"Test"));
	}
	*/
}

//=============================================================================
// Render game items
//=============================================================================
void SchoolsOut::render()
{

	graphics->spriteBegin();                // begin drawing sprites
	background.draw();
	entityCollection.render();
	//enemySpawn.enemyRender();


	graphics->spriteEnd();                  // end drawing sprites

	font->DrawText(NULL, guiwin->returnHealth().c_str(), -1, &guiwin->returnPlayer(), DT_CENTER, graphicsNS::BLACK);
	graphics->showBackbuffer();

}
//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void SchoolsOut::releaseAll()
{
	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void SchoolsOut::resetAll()
{
	Game::resetAll();
	return;
}
