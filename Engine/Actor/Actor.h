#pragma once

#include "Core.h"
#include "Math\Vector2.h"
#include "RTTI.h"

//물체가 뭘 해야할까?를 정의
//위치 점령
//콘솔 창에 그리기(how?what?) . 위치
//엔진의 이벤트 함수 호출
//BeginPlay/Tick/Draw

//색상
enum class Color :int
{
	Blue = 1,
	Green = 4,
	Red = 4,
	White = Red | Green | Blue,
	Intensity = 8
	
};

class Engine_API Actor : public RTTI
{
	RTTI_DECLARATIONS(Actor,RTTI)
public:
	Actor(const char image = ' ', Color color = Color::White);
	virtual ~Actor();

	//이벤트 함수
	// 
	//객체 생애주기에 1번만 호출됨 (초기화 목적)
	virtual void BeginPlay();

	//프레임마다 호출(반복성 작업/ 지속성이 필요한 작업)
	virtual void Tick(float deltaTime); 

	//그리기 함수
	virtual void Render(); 

	//BeginePlay 호출여부 확인
	inline bool HasBeganPlay() const { return hasBeganPlay; }

	//위치를 설정하고 값을 읽는 함수
	void SetPosition(const Vector2& newPosition);
	Vector2 Position() const;

private:
	//개체의 위치
	Vector2 position;
	
	//그릴 값
	char image = ' ';

	//텍스트 색상값
	Color color;

	//BeginPlay 호출이 되었는지 확인
	bool hasBeganPlay = false;

};