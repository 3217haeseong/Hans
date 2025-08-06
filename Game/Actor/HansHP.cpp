#include "HansHP.h"
#include "Utils/Utils.h"

HansHP::HansHP(Vector2 position)
	:Actor(" *", Color::Red)
{
	SetPosition(position);
	MaxHP = 5;
	CurrentHP = 5;
	xPosition = position.x;
}

void HansHP::BeginPlay()
{
	super::BeginPlay();
}

void HansHP::Tick(float deltaTime)
{
	super::Tick(deltaTime);
}

void HansHP::Render()
{
	for (int ix = 0; ix < CurrentHP; ++ix)
	{
		super::Render();
		position.x = position.x + 2;
	}
	position.x = xPosition;
	
	Utils::SetConsoleTextColor(Color::White);
}
