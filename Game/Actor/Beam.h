#pragma once
#include "Actor/Actor.h"
#include "Math/Vector2.h"
#include <ctime>

enum class Direction
{
	Up,
	Down,
	Left,
	Right
};



class Beam : public Actor
{
	RTTI_DECLARATIONS(Beam, Actor)
public:
	Beam(Vector2 position,Direction type);
	~Beam();

	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime);
	virtual void Render() override;

protected:
	Direction Type;
	int xPosition;
	int yPosition;

	clock_t start;
	clock_t end;
	int timer;
};