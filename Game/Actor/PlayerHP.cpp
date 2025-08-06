#include "PlayerHP.h"
#include "Math/Color.h"
#include "Math/Vector2.h"
#include "Utils/Utils.h"
#include <iostream>

PlayerHP::PlayerHP(Vector2 position)
	:Actor("-",Color::Red)
{
	SetPosition(position);
	MaxHP = 92.0f;
	CurrentHP = 92.0f;
	Ratio = 1;
	xPosition = this->position.x;
}

void PlayerHP::BeginPlay()
{
	super::BeginPlay();
}

void PlayerHP::Tick(float deltaTime)
{
	super::Tick(deltaTime);
	Ratio = GetRatio();
}

void PlayerHP::Render()
{
	for (int i = 0; i < (Ratio * 20); ++i)
	{
		super::Render();
		position.x = position.x + 1;
	}
	position.x = xPosition;

	Utils::SetConsoleTextColor(Color::White);
	Utils::SetCursorBoxByPos(39,position.y);
	std::cout << " " << GetHP();
	
}
