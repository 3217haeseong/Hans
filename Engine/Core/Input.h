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
		// 현재 프레임에 키가 눌렸는지 여부.
		bool isKeyDown = false;
		// 이전 프레임에 키가 눌렸는지 여부.
		bool previousKeyDown = false;
	};

public:
	Input();

	// 키 확인 함수.
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

	// 키 입력 정보 관리 변수.
	KeyState keyStates[255] = {};

	Phase GamePhase;

	static Input* instance;
};