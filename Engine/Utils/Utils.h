#pragma once

#include <Windows.h>
#include "Math/Vector2.h"
#include "Math/Color.h"
#include <iostream>
#include "dwrite.h"

// 프로젝트에서 다양하게 사용할 유틸리티 함수 모음.
namespace Utils
{

	// 두 값을 서로 바꿀 때 사용하는 함수.
	template<typename T>
	void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	// 콘솔 출력 핸들 가져오는 함수.
	inline HANDLE GetConsoleHandle()
	{
		return GetStdHandle(STD_OUTPUT_HANDLE);
	}
	

	// 콘솔 커서 위치 이동 함수.
	inline void SetConsolePosition(COORD coord)
	{
		static HANDLE handle = GetConsoleHandle();
		SetConsoleCursorPosition(handle, coord);
	}

	inline void SetConsolePosition(const Vector2& position)
	{
		SetConsolePosition(static_cast<COORD>(position));
	}

	// 콘솔 텍스트 색상 설정 함수.
	inline void SetConsoleTextColor(WORD color)
	{
		static HANDLE handle = GetConsoleHandle();
		SetConsoleTextAttribute(handle, color);
	}

	inline void SetConsoleTextColor(Color color)
	{
		static HANDLE handle = GetConsoleHandle();
		SetConsoleTextColor(static_cast<WORD>(color));
	}

	inline void SetCursorBoxByPos(int x,int y)
	{
		Vector2 position(x, 18+y);
		static HANDLE handle = GetConsoleHandle();
		SetConsolePosition(position);
	}

	inline void ReadFile(const char* filename, int type)
	{
		{
			char filepath[100] = {};
			sprintf_s(filepath, 100, "../Assets/%s", filename);

			FILE* file = nullptr;
			fopen_s(&file, filepath, "rt");

			if (type == 1)
			{
				std::locale::global(std::locale(".UTF-8"));
			}

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

					std::cout << "\n";
					if (type == 1)
					{
						std::cout << " ";
					}
					continue;
				}

				std::cout << mapCharacter;


			}

			// 버퍼 해제.
			delete[] buffer;

			// 파일 닫기.
			fclose(file);
		}
	}

	// 랜던 생성 함수.
	inline int Random(int min, int max)
	{
		int diff = (max - min) + 1;
		return ((diff * rand()) / (RAND_MAX + 1)) + min;
	}

	inline void BoxClear()
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


	inline float RandomFloat(float min, float max)
	{
		// 0 ~ 1 사이의 난수 구하기.
		float random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		return random * (max - min) + min;
	}
}

