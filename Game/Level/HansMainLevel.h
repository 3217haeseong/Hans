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

class HansMainLevel : public Level
{
public:
	HansMainLevel();

private:
	void ReadMapFile(const char* filename);

	void LoadConvesation(ConversationStep conversationstep);

	// 파일 열기
	FILE* OpenConversationFile(const char* filename);

	// 파일 한 줄씩 읽고 처리
	void ConversationOneLine(FILE* stepconversation);

	void LoadAttackStage();
};
