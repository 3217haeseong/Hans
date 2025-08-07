#include "Beam.h"
#include "Math/Vector2.h"
#include "Math/Color.h"
#include "Input.h"
#include "ctime"
#include "Utils/Utils.h"

Beam::Beam(Vector2 position, Direction type)
	:Actor (" ",Color::Blue)
{
	this->position = position;
	xPosition = position.x;
	yPosition = position.y;
	Type = type;

	if (type == Direction::Up)
	{
		strcpy_s(this->image, length + 1, "^");
	}
	else if (type == Direction::Down)
	{
		strcpy_s(this->image, length + 1, "-");
	}
	else if (type == Direction::Right)
	{
		strcpy_s(this->image, length + 1, ">");
	}
	else if (type == Direction::Left)
	{
		strcpy_s(this->image, length + 1, "<");
	}
	start = clock();
	end = clock();
}

Beam::~Beam()
{
	Utils::SetConsoleTextColor(Color::White);
}

void Beam::BeginPlay()
{
	super::BeginPlay();
}


void Beam::Tick(float deltaTime)
{
	super::Tick(deltaTime);
	end = clock();
	timer = (end - start) / CLOCKS_PER_SEC;
	if (timer > 1)
	{
		Utils::BoxClear();
		Destroy();
	}

}

void Beam::Render()
{
	if (Type == Direction::Up)
	{
		for (int jx = yPosition; jx > 0; jx--)
		{
			position.y = jx;
			for (int ix = 0; ix < 3; ++ix)
			{
				super::Render();
				position.x = position.x + 1;
			}
			position.x = xPosition;
		}
	}
	else if (Type == Direction::Down)
	{
		for (int jx = yPosition; jx <= 15; jx++)
		{
			position.y = jx;
			for (int ix = 0; ix < 3; ++ix)
			{
				super::Render();
				position.x = position.x + 1;
			}
			position.x = xPosition;
		
		}

	}
	else if (Type == Direction::Left)
	{
		for (int jx = 1; jx <= xPosition ; jx++)
		{
			position.x = jx;
			for (int ix = 0; ix < 3; ++ix)
			{
				super::Render();
				position.y = position.y + 1;
			}
			position.y = yPosition;
		}
	}
	else if (Type == Direction::Right)
	{
		for (int jx = xPosition; jx <= 87; jx++)
		{
			position.x = jx;
			for (int ix = 0; ix < 3; ++ix)
			{
				super::Render();
				position.y = position.y + 1;
			}
			position.y = yPosition;
		}
	}		
}
