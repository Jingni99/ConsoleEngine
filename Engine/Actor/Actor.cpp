#include "Actor.h"



Actor::Actor() 
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
}
