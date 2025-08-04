#include "HansMainLevel.h"
#include "iostream"
#include "Math/Vector2.h"
#include "Utils/Utils.h"
#include "Actor/AttackBar.h"

HansMainLevel::HansMainLevel()
{
	ReadFile("Hans.txt",0);
	LoadConversation(ConversationStep::Start);
	std::cin.get();
	BoxClear();
	LoadAttackStage();
}

void HansMainLevel::ReadFile(const char* filename, int type)
{
	char filepath[100] = {};
	sprintf_s(filepath, 100, "../Assets/%s", filename);

	FILE* file = nullptr;
	fopen_s(&file, filepath, "rt");

	if(type == 1)
	{
		std::locale::global(std::locale(".UTF-8"));
	}

	// ���� ó��.
	if (file == nullptr)
	{
		std::cout << "�� ���� �б� ����." << filename << "\n";
		__debugbreak();
		return;
	}

	// �Ľ�(Parcing, �ؼ�)
	fseek(file, 0, SEEK_END);
	size_t fileSize = ftell(file);
	rewind(file);

	// Ȯ���� ���� ũ�⸦ Ȱ���� ���� �Ҵ�.
	char* buffer = new char[fileSize + 1];
	//buffer[fileSize] = '\0';
	memset(buffer, 0, fileSize + 1);
	size_t readSize = fread(buffer, sizeof(char), fileSize, file);

	//if (fileSize != readSize)
	//{
	//	std::cout << "fileSize is not matched with readSize.\n";
	//}

	// �迭 ��ȸ�� ���� �ε��� ����.
	int index = 0;


	// ���ڿ� ���� ��.
	int size = (int)readSize;

	// x,y ��ǥ.
	//Vector2 position;

	// ���� �迭 ��ȸ.
	while (index < size)
	{
		// �� ���� Ȯ��.
		char mapCharacter = buffer[index++];

		// ���� ���� ó��.
		if (mapCharacter == '\n')
		{

			std::cout << "\n";
			if (type == 1)
			{
				std::cout << " ";
			}
			continue;
		}

		std::cout << mapCharacter;


	}

	// ���� ����.
	delete[] buffer;

	// ���� �ݱ�.
	fclose(file);
}

void HansMainLevel::LoadConversation(ConversationStep conversationstep)
{	
	Utils::SetCursorBoxStart();

	switch (conversationstep)
	{
		case ConversationStep::Start :
			ReadFile("StartConversation.txt",1);
			break;
		case ConversationStep::NoDamage :
			ReadFile("NoDamageConversation.txt", 1);
			break;
		case ConversationStep::OnDamage :
			ReadFile("OnDamage.txt", 1);
			break;
		case ConversationStep::PlayerDead :
			ReadFile("PlayerDeadConversation.txt", 1);
			break;

		case ConversationStep::Finish :
			ReadFile("FinishConversation.txt", 1);
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
	Utils::SetCursorBoxStart();
	ReadFile("Attack.txt",0);
	AddActor(new AttackBar);
}

