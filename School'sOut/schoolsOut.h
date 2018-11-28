// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 SchoolsOut.h v1.0

#ifndef _SCHOOLSOUT_H             // Prevent multiple definitions if this 
#define _SCHOOLSOUT_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "player.h"
#include "enemy.h"
#include "textureManager.h"
#include "image.h"
#include <list>

//=============================================================================
// This class is the core of the game
//=============================================================================
class SchoolsOut : public Game
{
private:
	// game items
	TextureManager stageTexture;	// stage texture
	TextureManager gameTexture;		// game texture
	
	
	Player player;
	Enemy enemy1;
	Enemy enemy2;
	Image background;

public:
	// Constructor
	SchoolsOut();

	// Destructor
	virtual ~SchoolsOut();

	// Initialize the game
	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void ai();          // "
	void collisions();  // "
	void render();      // "
	void releaseAll();
	void resetAll();
};

#endif
