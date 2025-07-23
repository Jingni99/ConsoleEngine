#include "Level.h"
#include"Actor/Actor.h"

Level::Level() {
}
Level::~Level(){
}

//������ ���͸� �߰��Ҷ� ���
void Level::AddActor(Actor* newActor)
{
	//push_back/emplace_back : �迭 �� �ڿ� ���ο� �׸� �߰��ϴ� �Լ�
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