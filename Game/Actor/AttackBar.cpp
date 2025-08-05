#include "AttackBar.h"
#include "Engine.h"
#include "Utils/Utils.h"
#include "Level/HansMainLevel.h"
#include <iostream>

AttackBar::AttackBar()
	: Actor("|", Color::Red)
{
	position.x = 1;
	position.y = 0;
	xPosition = 0;
}

void AttackBar::BeginPlay()
{
	super::BeginPlay();
}

void AttackBar::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	//xPosition += (deltaTime * 40);
	position.x = position.x + (deltaTime * 40);
	//position.x = (int)xPosition;

	if (position.x>88)
	{
		Utils::SetConsoleTextColor(Color::White);
		//GamePhase = Phase::AttackFail;
		Destroy();
		return;
	}

	SetPosition(Position());

	if (Input::Get().GetKeyDown(VK_SPACE))
	{
		Utils::SetConsoleTextColor(Color::White);
		if (isCollided())
		{
			//GamePhase = Phase::AttackSuccess;
		}
		else {
			//GamePhase = Phase::AttackFail;
		}
		Destroy();

		return;
	}
}

void AttackBar::Render()
{
	Utils::SetCursorBoxByPos(0, 0);
	Utils::ReadFile("Attack.txt",0);
	for (int i = 0; i < 16; i++)
	{
		super::Render();
		position.y = position.y + 1;
	}

	position.y = 0;
}

bool AttackBar::isCollided()
{
	if (position.x >= 44 && position.x <= 46)
	{
		return true;
	}
	else {
		return false;
	}

}

