#pragma once

#include <Windows.h>
#include "Math/Vector2.h"
#include "Math/Color.h"
#include <iostream>
#include "dwrite.h"

// ������Ʈ���� �پ��ϰ� ����� ��ƿ��Ƽ �Լ� ����.
namespace Utils
{

	// �� ���� ���� �ٲ� �� ����ϴ� �Լ�.
	template<typename T>
	void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	// �ܼ� ��� �ڵ� �������� �Լ�.
	inline HANDLE GetConsoleHandle()
	{
		return GetStdHandle(STD_OUTPUT_HANDLE);
	}
	

	// �ܼ� Ŀ�� ��ġ �̵� �Լ�.
	inline void SetConsolePosition(COORD coord)
	{
		static HANDLE handle = GetConsoleHandle();
		SetConsoleCursorPosition(handle, coord);
	}

	inline void SetConsolePosition(const Vector2& position)
	{
		SetConsolePosition(static_cast<COORD>(position));
	}

	// �ܼ� �ؽ�Ʈ ���� ���� �Լ�.
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
	}

	// ���� ���� �Լ�.
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
		// 0 ~ 1 ������ ���� ���ϱ�.
		float random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		return random * (max - min) + min;
	}
}

