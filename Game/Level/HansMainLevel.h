#pragma once
#include "Level/Level.h"

class HansMainLevel : public Level
{
public:
	HansMainLevel();

private:
	void ReadMapFile(const char* filename);

	void LoadConvesation(const char* filename);

	void LoadAttackStage();
};
