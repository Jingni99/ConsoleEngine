#include "Level.h"
#include"Actor/Actor.h"

Level::Level() {
}
Level::~Level(){
}

//레벨에 액터를 추가할때 사용
void Level::AddActor(Actor* newActor)
{
	//push_back/emplace_back : 배열 맨 뒤에 새로운 항목 추가하는 함수
	actors.emplace_back(newActor);
}

void Level::BeginPlay()
{
	for (Actor* const actor : actors) 
	{
		if (actor->HasBeganPlay()) 
		{
			continue;
		}
		actor->BeginPlay();
	}
}
void Level::Tick(float deltaTime) 
{
	for (Actor* const actor : actors)
	{
		actor->Tick(deltaTime);
	}
}
void Level::Render() 
{
	for (Actor* const actor : actors)
	{
		actor->Render();
	}
}