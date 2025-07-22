#pragma once

//#include "..\Core\Core.h"  //math ���� ENgine������Ʈ ���� core > core.h ������  �Ӽ�>#include "..\Core\Core.h" 
#include "Core.h" 

class Engine_API Vactor2
{
public:
	Vector2(int x = 0, int y = 0);
	~Vector2() = default; // �⺻ �Ҹ��� (��ȣ ����)

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;

	//���ڿ��� ���
	const char* ToString();

	static Vector2 Zero;
	static Vector2 One;
	static Vector2 Up;
	static Vector2 Right;

private:
	//x,y ��ǥ
	int x = 0;
	int y = 0;

	//���ڿ� ����
	char* value = nullptr;
};