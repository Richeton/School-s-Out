#ifndef _SEARCHINGSTATE_H            // Prevent multiple definitions if this 
#define _SEARCHINGSTATE_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "state.h"
#include "enemy.h"

class Entity;

class SearchingState : public State
{
private:

public:
	SearchingState();
	~SearchingState();

	void ai(float frameTime, Enemy & ent, Entity & t);

};

#endif
