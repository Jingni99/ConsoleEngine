#include "Actor.h"
#include <Windows.h>
#include <iostream>


Actor::Actor(const char image, Color color)
	:image(image), color(color)
{

}
Actor::~Actor()
{

}

//�̺�Ʈ �Լ�
// 
//��ü �����ֱ⿡ 1���� ȣ��� (�ʱ�ȭ ����)
void Actor::BeginPlay()
{
	hasBeganPlay = true;
}

//�����Ӹ��� ȣ��(�ݺ��� �۾�/ ���Ӽ��� �ʿ��� �۾�)
void Actor::Tick(float deltaTime)
{

}

//�׸��� �Լ�
void Actor::Render()
{
	//Win32 API
	//Ŀ�� ��ġ �̵�
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = (short)position.x;
	coord.Y = (short)position.y;
	//Ŀ�� �̵�
	SetConsoleCursorPosition(handle, coord);

	//���� ����
	SetConsoleTextAttribute(handle, (WORD)color);
	//�׸���
	std::cout << image;
}

void Actor::SetPosition(const Vector2& newPosition)
{
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = (short)position.x;
	coord.Y = (short)position.y;
	//Ŀ�� �̵�
	SetConsoleCursorPosition(handle, coord);

	std::cout << ' ';

	position = newPosition;
}

Vector2 Actor::Position() const
{
	return position;
}
