#pragma once

//#include "..\Core\Core.h"  //math 에서 ENgine프로잭트 가서 core > core.h 가져옴  속성>#include "..\Core\Core.h" 
#include "Core.h" 

class Engine_API Vactor2
{
public:
	Vector2(int x = 0, int y = 0);
	~Vector2() = default; // 기본 소멸자 (괄호 없는)

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;

	//문자열로 출력
	const char* ToString();

	static Vector2 Zero;
	static Vector2 One;
	static Vector2 Up;
	static Vector2 Right;

private:
	//x,y 좌표
	int x = 0;
	int y = 0;

	//문자열 변수
	char* value = nullptr;
};