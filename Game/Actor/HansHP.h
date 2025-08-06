#pragma once
#include "Actor/Actor.h"

class HansHP :public Actor
{
	RTTI_DECLARATIONS(HansHP, Actor)

public:
	HansHP(Vector2 position);

	inline int GetHP() { return CurrentHP; };
	inline void Damage() { CurrentHP = CurrentHP -1; }

	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Render() override;
private:
	int MaxHP;
	int CurrentHP;
	int xPosition;
};
