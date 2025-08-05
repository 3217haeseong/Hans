#include "HansMainLevel.h"
#include "iostream"
#include "Math/Vector2.h"
#include "Utils/Utils.h"
#include "Actor/AttackBar.h"
#include "Actor/Player.h"
#include "Level/Level.h"
#include "Input.h"

HansMainLevel::HansMainLevel()
{
	Utils::ReadFile("Hans.txt", 0);
	PreviousPhase = Phase::Attack;
	LoadConversation(ConversationStep::Start);
}

void HansMainLevel::BeginPlay()
{
	super::BeginPlay();

}

void HansMainLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	//Utils::SetCursorBoxByPos(0, -1);
	//Utils::ReadFile("Window.txt", 0);

	if (Input::Get().GetKeyDown(VK_SPACE))
	{
		if (Input::Get().GetGamePhase() == Phase::Conversation)
		{
			BoxClear();
			if (PreviousPhase == Phase::Attack)
			{
				// 방어 로드.
				Input::Get().SetGamePhase(Phase::Defence);
				LoadDefenceStage();
			}
			else if(PreviousPhase == Phase::Defence)
			{
				// 공격 로드.
				Input::Get().SetGamePhase(Phase::Attack);
				Utils::SetCursorBoxByPos(5, 5);
				std::cout << "Test";
				LoadAttackStage();
			}
		}
	}

	if (Input::Get().GetGamePhase() == Phase::DefenceSuccess)
	{
		 BoxClear();
		 Utils::SetCursorBoxByPos(0, -1);
		 CreateWin();
		 PreviousPhase = Phase::Defence;
	     LoadConversation(ConversationStep::DefenceSuccess);
	  
	}else if(Input::Get().GetGamePhase() ==Phase::DefenceFail)
	 {
		 BoxClear();
	     Utils::SetCursorBoxByPos(0, -1);
		 CreateWin();
		 PreviousPhase = Phase::Defence;
	     LoadConversation(ConversationStep::DefenceFail);
	 }
	

	// 공격 성공여부에 따라 실행
	if (Input::Get().GetGamePhase() ==Phase::AttackSuccess)
	{
		BoxClear();
		Utils::SetCursorBoxByPos(0, -1);
		CreateWin();
		PreviousPhase = Phase::Attack;
		LoadConversation(ConversationStep::OnDamage);
	}
	else if(Input::Get().GetGamePhase() == Phase::AttackFail){
		BoxClear();
		Utils::SetCursorBoxByPos(0, -1);
		CreateWin();
	    PreviousPhase = Phase::Attack;
		LoadConversation(ConversationStep::NoDamage);
	}

	

	// 플레이어가 죽었을 때
	//if ()
	//{
	//	//BoxClear();
	//	// LoadConversation("PlayerDeadConversation.txt");
	//}

	//// 샌즈가 죽었을 때
	//if ()
	//{
	//	//BoxClear();
	//	// LoadConversation("FinishConversation.txt");
	//	// 축하합니다 메시지
	//}



}

void HansMainLevel::Render()
{
	super::Render();
}


void HansMainLevel::CreateWin()
{
	Utils::ReadFile("Window.txt",0);
}

void HansMainLevel::LoadConversation(ConversationStep conversationstep)
{	
	Utils::SetConsoleTextSize(5);
	Input::Get().SetGamePhase( Phase::Conversation);
	Utils::SetCursorBoxByPos(1,0);

	switch (conversationstep)
	{
		case ConversationStep::Start :
			Utils::ReadFile("StartConversation.txt",1);
			break;
		case ConversationStep::NoDamage :
			Utils::ReadFile("NoDamageConversation.txt", 1);
			break;
		case ConversationStep::OnDamage :
			Utils::ReadFile("OnDamageConversation.txt", 1);
			break;
		case ConversationStep::PlayerDead :
			Utils::ReadFile("PlayerDeadConversation.txt", 1);
			break;
		case ConversationStep::DefenceSuccess:
			Utils::ReadFile("DefenceSuccess.txt", 1);
			break;
		case ConversationStep::DefenceFail:
			Utils::ReadFile("DefenceFail.txt",1);
			break;
		case ConversationStep::Finish :
			Utils::ReadFile("FinishConversation.txt", 1);
			break;
	}
	Utils::SetConsoleTextSize(2);
}


void HansMainLevel::BoxClear()
{
	
	for (int line = 18; line <= 33; line++)
	{
		Utils::SetConsolePosition(Vector2(1, line));
		for (int ix = 1; ix < 87; ix++)
		{
			std::cout << " ";
		}
		std::cout << "\n";
	}
	
}

void HansMainLevel::LoadAttackStage()
{
	AttackBar* attackbar = new AttackBar();
	AddActor(attackbar);

	
}

void HansMainLevel::LoadDefenceStage()
{
	Utils::SetCursorBoxByPos(5,5);
	std::cout << "Test\n";
	Input::Get().SetGamePhase(Phase::DefenceFail);
}

