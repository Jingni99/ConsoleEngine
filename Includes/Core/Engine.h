#pragma once

#include "Core.h"
#include<Windows.h>


class Engine_API Engine {
public:
	//������
	Engine();
	
	//�Ҹ���
	~Engine();

	//���� ���� �Լ�
	void Run();

	//���� �Լ�
	void Quit();

private: //������ 

	
	//���� �ϵ��� {} ���ְ� ; ����.
	void ProcessInput();

	void Update(float deltaTime = 0.0f);

	void Render();


private: //�Լ��ε� �ܺ� ���� ���Ұ�
	//�������� �÷���
	bool isQuit = false;  //bool�� byte �ü������ �ٸ� �� ����. ǥ���� ���� ũ�� ���� x �ñ��ϸ� sizeof ��
};