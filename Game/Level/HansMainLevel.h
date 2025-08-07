#pragma once
#include "Level/Level.h"
#include "Input.h"
#include "Actor/HansHP.h"
#include "Actor/PlayerHp.h"
#include "ctime"

enum class ConversationStep
{
	Start = 1,
	NoDamage,
	OnDamage,
	PlayerDead,
	DefenceSuccess,
	DefenceFail,
	Finish
};



class HansMainLevel : public Level
{
	RTTI_DECLARATIONS(HansMainLevel, Level )

public:

	HansMainLevel();

	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Render() override;

private:
	//void ReadFile(const char* filename,int type);

	void CreateWin();

	void LoadConversation(ConversationStep conversationstep);

	void LoadAttackStage();

	void LoadBeamStage();

	void ClearHP(Vector2 position);

private:
	Phase PreviousPhase;

	PlayerHP* playerhp;

	HansHP* hanshp;
	
	Vector2 ToDown;
	Vector2 ToUp;
	Vector2 ToRight;
	Vector2 ToLeft;

	clock_t start;
	clock_t end;
	int timer;


};
