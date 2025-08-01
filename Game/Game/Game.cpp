#include "Game.h"
#include "Level/HansMainLevel.h"


Game::Game()
{
	AddLevel(new HansMainLevel); 
}
