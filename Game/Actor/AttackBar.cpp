#include "AttackBar.h"
#include "Engine.h"
#include "Utils/Utils.h"
#include "Level/HansMainLevel.h"
#include <iostream>
#include "Input.h"


AttackBar::AttackBar()
	: Actor("|", Color::Red)
{
	position.x = 1;
	position.y = 0;
	xPosition = 0;
}

AttackBar::~AttackBar()
{
	
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

	if (Input::Get().GetKeyDown(VK_SPACE))
	{

		Utils::SetConsoleTextColor(Color::White);
		if (isCollided())
		{
			Input::Get().SetGamePhase(Phase::AttackSuccess);
		}
		else {
			Input::Get().SetGamePhase(Phase::AttackFail);
		}
		Destroy();

		return;
	}

	
	if (position.x>88)
	{
		Utils::SetConsoleTextColor(Color::White);
		Input::Get().SetGamePhase(Phase::AttackFail);
		Destroy();
		return;
	}
	
	SetPosition(Position());

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
	if (position.x >= 46 && position.x <= 48)
	{
		return true;
	}
	else {
		return false;
	}

}

