#pragma once
#include "Actor/Actor.h"

class Player : public Actor
{
	RTTI_DECLARATIONS(Player,Actor);

public:
	Player(const char* image);
private:

};