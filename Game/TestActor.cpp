#include "TestActor.h"
#include <iostream>
#include <Windows.h>
#include "Engine.h"

TestActor::TestActor()
	: Actor('P', Color::Red)
{
}

void TestActor::Tick(float deltaTime)
{
	//Actor::Tick(deltaTime);
	super::Tick(deltaTime);

	//std::cout
	//	<< "TestActor::Tick. FPS: "
	//	<< (1.0f / deltaTime)
	//	<< "\n";

	if (Engine::Get().GetKey(VK_RIGHT) && Position().x < 30)
	{
		Vector2 position = Position();
		position.x += 1;
		SetPosition(position);
	}


	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().Quit();
	}
}