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

}

//=============================================================================
// Destructor
//=============================================================================
SchoolsOut::~SchoolsOut()
{
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


	entityCollection.addEntity(player);
	entityCollection.addEntity(enemy1);

	// player
	if (!player->initialize(this, playerNS::WIDTH, playerNS::HEIGHT, playerNS::TEXTURE_COLS, &gameTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing player"));

	// enemy1
	if (!enemy1->initialize(this, enemyNS::WIDTH, enemyNS::HEIGHT, enemyNS::TEXTURE_COLS, &gameTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing enemy"));

	// Set player position to a center of the game boundaries
	player->setX(GAME_BOUNDARY_XSTART + (GAME_BOUNDARY_XEND - GAME_BOUNDARY_XSTART) / 2);
	player->setY(GAME_BOUNDARY_YSTART + (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART) / 2);


	// Set enemy1 position to left of the game boundaries 
	enemy1->setX(GAME_BOUNDARY_XSTART);
	enemy1->setY(GAME_BOUNDARY_YSTART + (GAME_BOUNDARY_YEND - GAME_BOUNDARY_YSTART) / 2);



	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void SchoolsOut::update()
{
	entityCollection.entityUpdate(frameTime);
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void SchoolsOut::ai()
{
	// enemy1's ai follows player
	entityCollection.entityAI(frameTime, player);

}

//=============================================================================
// Handle collisions
//=============================================================================
void SchoolsOut::collisions()
{
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
	entityCollection.entityRender();
	enemy1->setCurrentFrame(17);
	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void SchoolsOut::releaseAll()
{
	//    nebulaTexture.onLostDevice();
	//    gameTextures.onLostDevice();
	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void SchoolsOut::resetAll()
{
	//    gameTextures.onResetDevice();
	//    nebulaTexture.onResetDevice();
	Game::resetAll();
	return;
}
