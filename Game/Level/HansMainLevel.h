#pragma once
#include "Level/Level.h"

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

enum class Phase
{
	Conversation = 1,
	Attack,
	Defence,
	AttackSuccess,
	AttackFail,
	DefenceSuccess,
	DefenceFail
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

	void LoadDefenceStage();
	
	Phase GamePhase;

private:
	Phase PreviousPhase;

};
