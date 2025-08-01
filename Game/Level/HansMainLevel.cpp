#include "HansMainLevel.h"
#include "iostream"
#include <cstdio>
#include <wchar.h>

HansMainLevel::HansMainLevel()
{
	ReadMapFile("Hans.txt");
}

void HansMainLevel::ReadMapFile(const char* filename)
{

	char filepath[100] = {};
	sprintf_s(filepath, 100, "../Assets/%s", filename);

	FILE* file = nullptr;
	fopen_s(&file, filepath, "rt");

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
			// ���� �ٷ� �ѱ�鼭, x ��ǥ �ʱ�ȭ.
			//++position.y;
			//position.x = 0;

			std::cout << "\n";
			continue;
		}


		std::cout << mapCharacter;
	

	}

	// ���� ����.
	delete[] buffer;

	// ���� �ݱ�.
	fclose(file);
}
