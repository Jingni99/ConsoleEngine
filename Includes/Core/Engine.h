#pragma once

#include "Core.h"
#include<Windows.h>

/*
*Todo: 23일 할 것
* 키 입력 관리(keySatate 배열)  - 완료
* 입력 확인 함수(Getkey, Getkeydown, Getkeyup)  - 완료

* Entity 추가 (Actor)
* 이벤트 함수 추가 (BeginPlay, Tick, Render)
* Level 추가 (가상공간에 배치된 물체(Actor) 관리 객체)
*/


class Level; // 레벨 전방선언
class Engine_API Engine 
{
	//키 입력 확인을 위한 구조체
	struct KeyState
	{
		//현재 프레임에 키가 눌렸는지 여부
		bool isKeyDown = false;

		//이전 프레임에 키가 눌렸는지 여부
		bool previouseKeyDown = false;
	};

public:
	//생성자
	Engine();
	
	//소멸자
	~Engine();

	//엔진 실행 함수
	void Run();

	//레벨 추가 함수
	void AddLevel(Level* newLevel);


	//키 확인 함수
	bool GetKey(int keyCode);
	bool GetKeyDown(int keyCode);
	bool GetKeyUp(int keyCode);

	//종료 함수
	void Quit();

private: //변수형 

	
	//선언만 하도록 {} 없애고 ; 붙임.
	void ProcessInput();

	void BeginePlay();
	void Tick(float deltaTime = 0.0f); 

	void Render();


private: //함수인데 외부 공개 안할거
	//엔진종료 플래그
	bool isQuit = false;  //bool은 byte 운영체제마다 다를 수 있음. 표준이 없음 크기 추정 x 궁금하면 sizeof ㄱ
	
	//키 입력 정보 관리 변수
	KeyState keyStates[255] = {};

	//메인 레벨
	Level* mainLevel = nullptr;
};