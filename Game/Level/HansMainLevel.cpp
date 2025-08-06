#include "HansMainLevel.h"
#include "iostream"
#include "Math/Vector2.h"
#include "Utils/Utils.h"
#include "Actor/AttackBar.h"
#include "Actor/Player.h"
#include "Level/Level.h"
#include "Input.h"
#include "Actor/PlayerHp.h"
#include "Engine.h"
#include "Actor/Beam.h"
#include "Actor/Warning.h"

HansMainLevel::HansMainLevel()
{
	Utils::ReadFile("Hans.txt", 0);
	Utils::SetCursorBoxByPos(10, 17);
	std::cout << "HP :";

	playerhp = new PlayerHP(Vector2(17, 17));
	AddActor(playerhp);

	hanshp = new HansHP(Vector2(64, 17));
	AddActor(hanshp);

	PreviousPhase = Phase::Attack;
	LoadConversation(ConversationStep::Start);
}

void HansMainLevel::BeginPlay()
{
	super::BeginPlay();

}

#define Test 0

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
				CreateWin();
				Input::Get().SetGamePhase(Phase::Defence);
				LoadBeamStage();
			}
			else if(PreviousPhase == Phase::Defence)
			{
				// 공격 로드.
				CreateWin();
				Input::Get().SetGamePhase(Phase::Attack);
				LoadAttackStage();
			}
		}
	}

	if (Input::Get().GetGamePhase() == Phase::DefenceSuccess)
	{
		 BoxClear();
		 CreateWin();
		 PreviousPhase = Phase::Defence;
	     LoadConversation(ConversationStep::DefenceSuccess);
	  
	}else if(Input::Get().GetGamePhase() ==Phase::DefenceFail)
	 {
		 BoxClear();
		 CreateWin();
		 PreviousPhase = Phase::Defence;
	     LoadConversation(ConversationStep::DefenceFail);
	 }
	

	// 공격 성공여부에 따라 실행
	if (Input::Get().GetGamePhase() ==Phase::AttackSuccess)
	{
		ClearHP(Vector2(64, 17));
		hanshp->Damage();
		BoxClear();
		CreateWin();
		PreviousPhase = Phase::Attack;
		LoadConversation(ConversationStep::OnDamage);
	}
	else if(Input::Get().GetGamePhase() == Phase::AttackFail){
		
		BoxClear();
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

	// 샌즈가 죽었을 때
#if !Test
	if (hanshp->GetHP() == 0)
#else
#endif
	{
		ClearHP(Vector2(64, 17));
		BoxClear();
		CreateWin();
		LoadConversation(ConversationStep::Finish);
		Utils::SetCursorBoxByPos(0, 18);
		while (1)
		{
			//if (Input::Get().GetKeyDown(VK_ESCAPE))
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			{
				Engine::Get().Quit();
				break;
			}
		}
	}
}

void HansMainLevel::Render()
{
	super::Render();
}


void HansMainLevel::CreateWin()
{
	Utils::SetCursorBoxByPos(0, -1);
	Utils::ReadFile("Window.txt",0);
}

void HansMainLevel::LoadConversation(ConversationStep conversationstep)
{	
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

void HansMainLevel::LoadBeamStage()
{
	Player* player = new Player(Vector2(43, 8));
	AddActor(player);

	Vector2 ToDown=Vector2(Utils::Random(0,87),Utils::Random(0,15) );
	Vector2 ToUp= Vector2(Utils::Random(0,87),Utils::Random(1,16) );
	Vector2 ToRight = Vector2(Utils::Random(0,45),Utils::Random(0,13) );
	Vector2 ToLeft= Vector2(Utils::Random(46,88),Utils::Random(0,13) );
	
	AddActor(new Warning(ToDown, Direction::Down));
	AddActor(new Warning(ToUp, Direction::Up));
	AddActor(new Warning(ToRight, Direction::Right));
	AddActor(new Warning(ToLeft, Direction::Left));
	
	//시간이 넘어야 아래 실행.

	AddActor(new Beam(ToDown, Direction::Down));
	AddActor(new Beam(ToUp, Direction::Up));
	AddActor(new Beam(ToRight, Direction::Right));
	AddActor(new Beam(ToLeft, Direction::Left));


	//Input::Get().SetGamePhase(Phase::DefenceFail);
}

void HansMainLevel::ClearHP(Vector2 position)
{
	Utils::SetCursorBoxByPos(position.x,position.y);
	for (int i = 0; i < 20; i++)
	{
		std::cout << " ";
	}

}




