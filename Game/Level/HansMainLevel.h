#pragma once
#include "Level/Level.h"

enum class ConversationStep
{
	Start = 1,
	NoDamage,
	OnDamage,
	PlayerDead,
	Finish

};

enum class Phase
{

};

class HansMainLevel : public Level
{
public:
	HansMainLevel();

private:
	void ReadFile(const char* filename,int type);

	void LoadConversation(ConversationStep conversationstep);

	// 파일 열기
	FILE* OpenConversationFile(const char* filename);

	void BoxClear();

	void LoadAttackStage();
};
