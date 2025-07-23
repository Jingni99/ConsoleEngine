#pragma once
#include "Core.h"
#include <vector>  //크기가 알아서 변경되는 동적배열 vector.


class Actor;
class Engine_API Level
{
public:
	Level();
	virtual ~Level();

	//레벨에 액터를 추가할때 사용
	void AddActor(Actor* newActor);

	virtual void BeginPlay();
	virtual void Tick(float deltaTime);
	virtual void Render();

private:
	//레벨에 배치된 모든 액터를 관리하는 배열
	std::vector<Actor*> actors;
};