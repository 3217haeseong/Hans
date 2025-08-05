#pragma once

#include "Core.h"

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


class Engine_API Input
{
	friend class Engine;

	struct KeyState
	{
		// ���� �����ӿ� Ű�� ���ȴ��� ����.
		bool isKeyDown = false;
		// ���� �����ӿ� Ű�� ���ȴ��� ����.
		bool previousKeyDown = false;
	};

public:
	Input();

	// Ű Ȯ�� �Լ�.
	bool GetKey(int keyCode);
	bool GetKeyDown(int keyCode);
	bool GetKeyUp(int keyCode);

	inline Phase& GetGamePhase() { return GamePhase; }
	inline void SetGamePhase(Phase phase) { GamePhase = phase;  }

	static Input& Get();

private:
	void ProcessInput();
	void SavePreviousKeyStates();

private:

	// Ű �Է� ���� ���� ����.
	KeyState keyStates[255] = {};

	Phase GamePhase;

	static Input* instance;
};