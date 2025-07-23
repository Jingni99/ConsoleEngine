#pragma once

#include "Core.h"
#include "Math\Vector2.h"
//��ü�� �� �ؾ��ұ�?�� ����
//��ġ ����
//�ܼ� â�� �׸���(how?what?) . ��ġ
//������ �̺�Ʈ �Լ� ȣ��
//BeginPlay/Tick/Draw

class Engine_API Actor {

public:
	Actor();
	virtual ~Actor();

	//�̺�Ʈ �Լ�
	// 
	//��ü �����ֱ⿡ 1���� ȣ��� (�ʱ�ȭ ����)
	virtual void BeginPlay();

	//�����Ӹ��� ȣ��(�ݺ��� �۾�/ ���Ӽ��� �ʿ��� �۾�)
	virtual void Tick(float deltaTime); 

	//�׸��� �Լ�
	virtual void Render(); 

	//BeginePlay ȣ�⿩�� Ȯ��
	inline bool HasBeganPlay() const { return hasBeganPlay; }

private:
	//��ü�� ��ġ
	Vector2 position;
	
	//�׸� ��
	char image = ' ';

	//BeginPlay ȣ���� �Ǿ����� Ȯ��
	bool hasBeganPlay = false;

};