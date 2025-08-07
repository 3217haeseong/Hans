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
#include "ctime"

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

	if (Input::Get().GetKeyDown(VK_ESCAPE))
	{
		// 게임 종료.
		Engine::Get().Quit();
		return;
	}

	if (Input::Get().GetKeyDown(VK_SPACE))
	{
		if (Input::Get().GetGamePhase() == Phase::Conversation)
		{
			Utils::BoxClear();
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
		 Utils::BoxClear();
		 CreateWin();
		 PreviousPhase = Phase::Defence;
	     LoadConversation(ConversationStep::DefenceSuccess);
	  
	}else if(Input::Get().GetGamePhase() ==Phase::DefenceFail)
	 {
		 Utils::BoxClear();
		 CreateWin();
		 PreviousPhase = Phase::Defence;
	     LoadConversation(ConversationStep::DefenceFail);
	 }
	

	// 공격 성공여부에 따라 실행
	if (Input::Get().GetGamePhase() ==Phase::AttackSuccess)
	{
		ClearHP(Vector2(64, 17));
		hanshp->Damage();
		Utils::BoxClear();
		CreateWin();
		PreviousPhase = Phase::Attack;
		LoadConversation(ConversationStep::OnDamage);
	}
	else if(Input::Get().GetGamePhase() == Phase::AttackFail){
		
		Utils::BoxClear();
		CreateWin();
	    PreviousPhase = Phase::Attack;
		LoadConversation(ConversationStep::NoDamage);
	}

	if (Input::Get().GetGamePhase() == Phase::AlertDelay)
	{
		end = clock();
		timer = (end - start) / CLOCKS_PER_SEC;

		
		if (timer > 0.75)
		{
			//Todo: 방어 완성.
			//if()
			Input::Get().SetGamePhase(Phase::BeamAttack);
		}

	}

	if (Input::Get().GetGamePhase() == Phase::BeamAttack)
	{
		PreviousPhase = Phase::Attack;
		
		AddActor(new Beam(ToDown, Direction::Down));
		AddActor(new Beam(ToUp, Direction::Up));
		AddActor(new Beam(ToRight, Direction::Right));
		AddActor(new Beam(ToLeft, Direction::Left));

		Input::Get().SetGamePhase(Phase::AfterAttack);
		start = clock();
		// 충돌 처리
		/*if ()
		{
			Input::Get().SetGamePhase(Phase::AttackSuccess);
		}
		else
		{
			Input::Get().SetGamePhase(Phase::AttackFail);
		}*/
	}

	if (Input::Get().GetGamePhase() == Phase::AfterAttack)
	{
		end = clock();
		timer = (end - start) / CLOCKS_PER_SEC;

		if (timer > 1)
		{
			//Todo: 방어 완성.
			//if()
			Input::Get().SetGamePhase(Phase::DefenceSuccess);
		}
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
		Utils::BoxClear();
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



void HansMainLevel::LoadAttackStage()
{
	AttackBar* attackbar = new AttackBar();
	AddActor(attackbar);
	
}

void HansMainLevel::LoadBeamStage()
{
	Input::Get().SetGamePhase(Phase::Attack);
	/*Player* player = new Player(Vector2(43, 8));
	AddActor(player);*/

	ToDown=Vector2(Utils::Random(0,86),Utils::Random(3,15) );
	ToUp= Vector2(Utils::Random(0,86),Utils::Random(1,15) );
	ToRight = Vector2(Utils::Random(0,45),Utils::Random(0,13) );
	ToLeft= Vector2(Utils::Random(46,87),Utils::Random(0,13) );

	start = clock();
	AddActor(new Warning(ToDown, Direction::Down));
	AddActor(new Warning(ToUp, Direction::Up));
	AddActor(new Warning(ToRight, Direction::Right));
	AddActor(new Warning(ToLeft, Direction::Left));

	Input::Get().SetGamePhase(Phase::AlertDelay);
}

void HansMainLevel::ClearHP(Vector2 position)
{
	Utils::SetCursorBoxByPos(position.x,position.y);
	for (int i = 0; i < 20; i++)
	{
		std::cout << " ";
	}

}




