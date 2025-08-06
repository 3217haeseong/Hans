#pragma once
#include "Level/Level.h"
#include "Input.h"
#include "Actor/HansHP.h"
#include "Actor/PlayerHp.h"

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

	void BoxClear();

	void LoadAttackStage();

	void LoadBeamStage();

	void ClearHP(Vector2 position);

	

private:
	Phase PreviousPhase;

	PlayerHP* playerhp;

	HansHP* hanshp;

};
