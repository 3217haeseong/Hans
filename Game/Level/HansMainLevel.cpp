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

	// 예외 처리.
	if (file == nullptr)
	{
		std::cout << "맵 파일 읽기 실패." << filename << "\n";
		__debugbreak();
		return;
	}

	// 파싱(Parcing, 해석)
	fseek(file, 0, SEEK_END);
	size_t fileSize = ftell(file);
	rewind(file);

	// 확인한 파일 크기를 활용해 버퍼 할당.
	char* buffer = new char[fileSize + 1];
	//buffer[fileSize] = '\0';
	memset(buffer, 0, fileSize + 1);
	size_t readSize = fread(buffer, sizeof(char), fileSize, file);

	//if (fileSize != readSize)
	//{
	//	std::cout << "fileSize is not matched with readSize.\n";
	//}

	// 배열 순회를 위한 인덱스 변수.
	int index = 0;

	// 문자열 길이 값.
	int size = (int)readSize;

	// x,y 좌표.
	//Vector2 position;

	// 문자 배열 순회.
	while (index < size)
	{
		// 맵 문자 확인.
		char mapCharacter = buffer[index++];

		// 개행 문자 처리.
		if (mapCharacter == '\n')
		{
			// 다음 줄로 넘기면서, x 좌표 초기화.
			//++position.y;
			//position.x = 0;

			std::cout << "\n";
			continue;
		}


		std::cout << mapCharacter;
	

	}

	// 버퍼 해제.
	delete[] buffer;

	// 파일 닫기.
	fclose(file);
}
