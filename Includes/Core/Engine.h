#pragma once

#include "Core.h"
#include<Windows.h>

/*
*Todo: 24�� �� ��
-RTTI����
-Engine �̱���(Singleton) ����
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

	//�̱��� ���� �Լ�
	static Engine& Get();

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

	//�̱��� ����
	static Engine* instance;

};