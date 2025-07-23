#pragma once
#include "Core.h"
#include <vector>  //ũ�Ⱑ �˾Ƽ� ����Ǵ� �����迭 vector.


class Actor;
class Engine_API Level
{
public:
	Level();
	virtual ~Level();

	//������ ���͸� �߰��Ҷ� ���
	void AddActor(Actor* newActor);

	virtual void BeginPlay();
	virtual void Tick(float deltaTime);
	virtual void Render();

private:
	//������ ��ġ�� ��� ���͸� �����ϴ� �迭
	std::vector<Actor*> actors;
};