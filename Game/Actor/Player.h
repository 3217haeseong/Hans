#pragma once
#include "Actor/Actor.h"

class Player : public Actor
{
	RTTI_DECLARATIONS(Player, Actor)

public:
	Player(Vector2 position);
	
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Render() override;


private:



};