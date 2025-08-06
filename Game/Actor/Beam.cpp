#include "Beam.h"
#include "Math/Vector2.h"
#include "Math/Color.h"
#include "Input.h"

Beam::Beam(Vector2 position, Direction type)
	:Actor (" ",Color::Blue)
{
	SetPosition(position);
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
		strcpy_s(this->image, length + 1, "]");
	}
	else if (type == Direction::Left)
	{
		strcpy_s(this->image, length + 1, "[");
	}
}

Beam::~Beam()
{
}

void Beam::BeginPlay()
{
	super::BeginPlay();
}


void Beam::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	//충돌 처리.

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
		for (int jx = 0; jx <= xPosition ; jx++)
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
		for (int jx = xPosition; jx <= 89; jx++)
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
