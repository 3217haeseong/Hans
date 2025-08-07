#pragma once
#include "Actor/Actor.h"
#include "Beam.h"
#include <ctime>

class Warning : public Beam
{

	RTTI_DECLARATIONS(Warning, Beam)
public:
	Warning(Vector2 position, Direction type);
	~Warning();
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Render() override;

private:
	
};
