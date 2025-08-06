#pragma once
#include "Actor/Actor.h"
	
class PlayerHP : public Actor
{
	RTTI_DECLARATIONS(PlayerHP, Actor)

public:
	PlayerHP(Vector2 Position);

	inline void SetHP(float hp) { CurrentHP = hp; }
	inline float GetHP() { return CurrentHP; }

	inline float GetMaxHP() { return MaxHP; }

	inline float GetRatio() { return (CurrentHP / MaxHP); }

	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Render() override;

private:
	float MaxHP;
	float CurrentHP;
	int Ratio;
	int xPosition;
	
};