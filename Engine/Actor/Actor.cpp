#include "Actor.h"
#include "Engine.h"
#include "Utils/Utils.h"
#include "Level/Level.h"

#include <Windows.h>
#include <iostream>

Actor::Actor(const char* image, Color color, const Vector2& position)
	: color(color), position(position)
{
	SetWidthAndHeight(image);

	// �޸� �Ҵ�.
	this->image = new char[length+1 ];

	// ���ڿ� ����.
	strcpy_s(this->image, length+ 1, image);
}
Actor::~Actor()
{
	// �޸� ����.
	SafeDeleteArray(image);
}

// �̺�Ʈ �Լ�. 

// ��ü �����ֱ�(Lifetime)�� 1���� ȣ��� (�ʱ�ȭ ����).
void Actor::BeginPlay()
{
	hasBeganPlay = true;
}

// �����Ӹ��� ȣ�� (�ݺ��� �۾�/ ���Ӽ��� �ʿ��� �۾�).
void Actor::Tick(float deltaTime)
{

}

// �׸��� �Լ�. 
void Actor::Render()
{

	// Ŀ�� �̵�.
	//SetConsoleCursorPosition(handle, coord);
	//Utils::SetConsolePosition(position);
	//Utils::SetCursorBoxStart();
	Utils::SetCursorBoxByPos(position.x, position.y);
	// ���� ����.
	//SetConsoleTextAttribute(handle, (WORD)color);
	Utils::SetConsoleTextColor(color);
	// �׸���. 
	std::cout << image;

}

void Actor::SetPosition(const Vector2& newPosition)
{
	// ����ó�� (ȭ�� ������� Ȯ��.)

	// ���� �����ڸ��� ȭ���� �������.
	if (newPosition.x < 0)
	{
		return;
	}

	// ������ �����ڸ��� ȭ�� �������� �������.
	if (newPosition.x + 2 -1 >= 88)
	{
		return;
	}

	// ���� �����ڸ��� ȭ���� ���� �������
	if (newPosition.y >=19 )
	{
		return;
	}

	// ȭ�� �Ʒ��� �������
	if (newPosition.y - 1 <= 33)
	{

	}
	// ������ ������Ʈ ����.
	if (position == newPosition)
	{
		return;
	}

	// ���� ��ġ Ȯ��.
	Vector2 direction = newPosition - position;

	position.x = direction.x > 0 ? position.x : position.x + width - 1;

	Utils::SetConsolePosition(position);

	// ���ڿ� ���� ����ؼ� ���� ��ġ Ȯ���ؾ� ��.
	std::cout << ' ';

	position = newPosition;
}


Vector2 Actor::Position() const
{
	return position;
}

int Actor::ActorWidth() const
{
	return width;
}

int Actor::ActorHeight() const
{
	return height;
}

void Actor::SetWidthAndHeight(const char* image)
{
	int TempWidth=0;
	int MaxWidth = -1;
	int TempHeight=1;
	int i;

	for (i = 0; image[i] != '\0'; ++i)
	{
		if (image[i] == '\n')
		{
			++TempHeight;
			if (MaxWidth < TempWidth)
			{
				MaxWidth = TempWidth;
			}
			TempWidth = 0;
		}
		else {
			++TempWidth;
		}
	}

	if (MaxWidth < TempWidth)
	{
		MaxWidth = TempWidth;
		TempWidth = 0;
	}


	this->height = TempHeight;
	this->width = MaxWidth;
	this->length = i;
}


void Actor::SetSortingOrder(unsigned int sortingOrder)
{
	this->sortingOrder = sortingOrder;
}

void Actor::SetOwner(Level* newOwner)
{
	owner = newOwner;
}

Level* Actor::GetOwner()
{
	return owner;
}

bool Actor::TestIntersect(const Actor* const other)
{
	// AABB (Axis Aligned Bounding Box).
	// Note : ���� ���� ���� �� ���δ� ũ�Ⱑ ����(ũ�Ⱑ 1),
	//		  ���� ������ �ּ�/�ִ� ��ġ�� �� ����ϸ� ��.

	// �� ������ x ��ǥ ����.
	int xMin = position.x;
	int xMax = position.x + width - 1;

	// �浹 ���� �ٸ� ������ x ��ǥ ����.
	int otherXMin = other->position.x;
	int otherXMax = other->position.x + other->width - 1;

	// �Ȱ�ġ�� ���� Ȯ��.

	// �ٸ� ������ ���� ��ǥ�� �� ������ ��ǥ���� �� �����ʿ� ������ �� ��ħ.
	if (otherXMin > xMax)
	{
		return false;
	}

	// �ٸ� ������ ������ ��ǥ�� �� ���� ��ǥ���� �� ���ʿ� ������ �� ��ħ.
	if (otherXMax < xMin)
	{
		return false;
	}

	// y��ǥ�� ������ ���� Ȯ��.
	return position.y == other->position.y;

	// Todo : �⺻�� �����ؾ� ��.
	return false;
}

void Actor::Destroy()
{
	// ���� ��û �Ǿ��ٰ� ����.
	isExpired = true;

	// ������ ���� ��û.
	owner->DestroyActor(this);
}

void Actor::QuitGame()
{
	Engine::Get().Quit();
}


