#include "Warning.h"
#include "Utils/Utils.h"

Warning::Warning(Vector2 position, Direction type)
	:Beam(position, type)
{
	color = Color::Red;
}

Warning::~Warning()
{
	Utils::SetConsoleTextColor(Color::White);
}

void Warning::BeginPlay()
{
	super::BeginPlay();
}

void Warning::Tick(float deltaTime)
{
	end = clock();
	timer = (end - start) / CLOCKS_PER_SEC;
	if (timer > 0.75)
	{
		Utils::BoxClear();
		Destroy();
	}
}

void Warning::Render()
{
	if (Type == Direction::Up)
	{
		for (int ix=0;ix<3;ix++)
		{
			Actor::Render();
			position.x = position.x+1;
		}
		position.x = xPosition;
	}
	else if (Type == Direction::Down)
	{
		for (int ix = 0; ix < 3; ix++)
		{
			Actor::Render();
			position.x = position.x+1;
		}
		position.x = xPosition;
	}
	else if (Type == Direction::Left)
	{
		for (int ix = 0; ix < 3; ix++)
		{
			Actor::Render();
			position.y = position.y+1;
		}
		position.y = yPosition;
	}
	else if (Type == Direction::Right)
	{
		for (int ix = 0; ix < 3; ix++)
		{
			Actor::Render();
			position.y = position.y+1;
		}
		position.y = yPosition;
	}
}
