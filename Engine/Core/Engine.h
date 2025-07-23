#pragma once

#include "Core.h"
#include<Windows.h>

/*
*Todo: 23�� �� ��
* Ű �Է� ����(keySatate �迭)  - �Ϸ�
* �Է� Ȯ�� �Լ�(Getkey, Getkeydown, Getkeyup)  - �Ϸ�

* Entity �߰� (Actor)
* �̺�Ʈ �Լ� �߰� (BeginPlay, Tick, Render)
* Level �߰� (��������� ��ġ�� ��ü(Actor) ���� ��ü)
*/


class Level; // ���� ���漱��
class Engine_API Engine 
{
	//Ű �Է� Ȯ���� ���� ����ü
	struct KeyState
	{
		//���� �����ӿ� Ű�� ���ȴ��� ����
		bool isKeyDown = false;

		//���� �����ӿ� Ű�� ���ȴ��� ����
		bool previouseKeyDown = false;
	};

public:
	//������
	Engine();
	
	//�Ҹ���
	~Engine();

	//���� ���� �Լ�
	void Run();

	//���� �߰� �Լ�
	void AddLevel(Level* newLevel);


	//Ű Ȯ�� �Լ�
	bool GetKey(int keyCode);
	bool GetKeyDown(int keyCode);
	bool GetKeyUp(int keyCode);

	//���� �Լ�
	void Quit();

private: //������ 

	
	//���� �ϵ��� {} ���ְ� ; ����.
	void ProcessInput();

	void BeginePlay();
	void Tick(float deltaTime = 0.0f); 

	void Render();


private: //�Լ��ε� �ܺ� ���� ���Ұ�
	//�������� �÷���
	bool isQuit = false;  //bool�� byte �ü������ �ٸ� �� ����. ǥ���� ���� ũ�� ���� x �ñ��ϸ� sizeof ��
	
	//Ű �Է� ���� ���� ����
	KeyState keyStates[255] = {};

	//���� ����
	Level* mainLevel = nullptr;
};