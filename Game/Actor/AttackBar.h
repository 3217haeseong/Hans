#pragma once
#include "Actor/Actor.h"


class AttackBar : public Actor
{
	RTTI_DECLARATIONS(AttackBar, Actor)
public:
	AttackBar();
	
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Render() override;

	bool isCollided();

private:
	float MoveSpeed = 40.0f;

	float xPosition;

};