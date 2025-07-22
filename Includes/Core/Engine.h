#pragma once

#include "Core.h"
#include<Windows.h>


class Engine_API Engine {
public:
	//생성자
	Engine();
	
	//소멸자
	~Engine();

	//엔진 실행 함수
	void Run();

	//종료 함수
	void Quit();

private: //변수형 

	
	//선언만 하도록 {} 없애고 ; 붙임.
	void ProcessInput();

	void Update(float deltaTime = 0.0f);

	void Render();


private: //함수인데 외부 공개 안할거
	//엔진종료 플래그
	bool isQuit = false;  //bool은 byte 운영체제마다 다를 수 있음. 표준이 없음 크기 추정 x 궁금하면 sizeof ㄱ
};