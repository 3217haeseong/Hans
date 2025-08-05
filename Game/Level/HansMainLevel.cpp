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
	GamePhase = Phase::Conversation;
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
		if (GamePhase == Phase::Conversation)
		{
			BoxClear();
			if (PreviousPhase == Phase::Attack)
			{
				// ��� �ε�.
				GamePhase = Phase::Defence;
				LoadDefenceStage();
			}
			else
			{
				// ���� �ε�.
				GamePhase = Phase::Attack;
				LoadAttackStage();
			}
		}
	}

	//if (GamePhase==Phase::DefenceSuccess)
	//{
	//	 BoxClear();
	//	 PreviousPhase = Phase::Defence;
	//   LoadConversation(ConversationStep::DefenceSuccess);
	//  
	//}else if(GamePhase==Phase::DefenceFail)
	// {
	//	 BoxClear();
	//	 PreviousPhase = Phase::Defence;
	//   LoadConversation(ConversationStep::DefenceFail);
	// }
	//

	//// ���� �������ο� ���� ����
	//if (GamePhase==Phase::AttackSuccess)
	//{
	//		// ���� ���� ���� false��
	//		BoxClear();
	//		PreviousPhase = Phase::Defence;
	//		LoadConversation(ConversationStep::OnDamage);
	//}
	//else if(GamePhase==Phase::AttackFail){
	//	    BoxClear();
	//      PreviousPhase = Phase::Defence;
	//	    LoadConversation(ConversationStep::NoDamage);
	//}

	

	// �÷��̾ �׾��� ��
	//if ()
	//{
	//	//BoxClear();
	//	// LoadConversation("PlayerDeadConversation.txt");
	//}

	//// ��� �׾��� ��
	//if ()
	//{
	//	//BoxClear();
	//	// LoadConversation("FinishConversation.txt");
	//	// �����մϴ� �޽���
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
	GamePhase = Phase::Conversation;
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
			Utils::ReadFile("OnDamage.txt", 1);
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
	
	for (int line = 18; line <= 31; line++)
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
}

