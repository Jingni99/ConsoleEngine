#include "Engine.h"
#include<iostream>
#include"Level/Level.h"


//2가지 기능 추가
// 윈도우즈
//단순 입력 처리 (키보드).
//타이머(시간 계산).

Engine::Engine()
{
}

Engine::~Engine()
{
    //
    if (mainLevel) {
        delete mainLevel;
    }
}
void Engine::Run()
{
    //시간계산함수
   // float currentTime = timeGetTime();
    LARGE_INTEGER currentTime;// 2.Large- INteger로
    LARGE_INTEGER previousTime; //3
    QueryPerformanceCounter(&currentTime);  // 1. 함수 f12 로 가서 확인 
    previousTime = currentTime; //4
    //프레임시간 계산 .. 밀리세컨즈는 초 계산 1/1000 ms >> 초

    //하드웨어 시계의 정밀도(주파수)가져오기
    //나중에 초로 변환하기 위함.
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    //** 타겟 프레임
    float targetFrameRate = 60.0f;

    //** 타겟 한 프레임 시간
    float oneFrameTime = 1.0f / targetFrameRate;

    // GameLoop.
    while (true)
    {
        //엔진 종료여부 확인
        if (isQuit) {
            //루프 종료
            break;
        }

        


        //프레임 시간 계산
        //(현재시간 - 이전시간) / 주파수  = 초단위.
        QueryPerformanceCounter(&currentTime);

        ////프레임시간 1
        //float daltaTime = (currentTime.QuadPart - previousTime.QuadPart) / (float)frequency.QuadPart;
        //** 프레임시간 개선 코드 (프레임 제안 걸기) - 위에 타겟 프레임
        float deltaTime = (currentTime.QuadPart - previousTime.QuadPart) / (float)frequency.QuadPart;


        //
        //입력은 최대한 빨리
        ProcessInput(); // 주파수 얼만지 f9찍고 확인 주파수가 천만이면 얼마임..?
        
        if (deltaTime >= oneFrameTime)
        {
            BeginePlay();
            Tick(deltaTime);
            Render();

            //시간 업데이트
            previousTime = currentTime;

            //현재 프레임의 입력을 기록
            for (int ix = 0; ix < 255; ++ix)
            {
                keyStates[ix].previouseKeyDown = keyStates[ix].isKeyDown;  
            }
        }


    }

}

void Engine::AddLevel(Level* newLevel)
{
    //기존에 있던 레벨 제거
    if (mainLevel) {
        delete mainLevel;
    }
    mainLevel = newLevel;
}

bool Engine::GetKey(int keyCode)
{
    return keyStates[keyCode].isKeyDown;
}

bool Engine::GetKeyDown(int keyCode)
{
    return !keyStates[keyCode].previouseKeyDown && keyStates[keyCode].isKeyDown;  // true false && 연산
}

bool Engine::GetKeyUp(int keyCode)
{
    return keyStates[keyCode].previouseKeyDown && !keyStates[keyCode].isKeyDown;;
}

void Engine::Quit()
{
    //종료 플래그 설정
    isQuit = true;
}

void Engine::ProcessInput()
{
    
    //키 입력 확인
    for(int ix =0 ; ix < 255; ++ix)
    {
        keyStates[ix].isKeyDown = GetAsyncKeyState(ix) & 0x8000;
    }

    ////Esc 키 눌림 확인{
    //if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    //{
    //    //종료
    //    Quit();
    //}
}



void Engine::BeginePlay()
{
    if (mainLevel)
    {
        mainLevel->BeginPlay();
    }

}
void Engine::Tick(float deltaTime)
{
    //std::cout << "DeltaTime:" << deltaTime << ",FPS: " <<(1.0f/deltaTime) << "\n";  // fps 는 순간 타임
    
    //if (GetKeyDown('A'))
    //{
    //    std::cout << "keyDown\n";
    //}
    //if (GetKey('A'))
    //{
    //    std::cout << "key\n";
    //}
    //if (GetKeyUp('A'))
    //{
    //    std::cout << "keyUp\n";
    //}

    //레벨 업데이트
    if (mainLevel) 
    {
        mainLevel->Tick(deltaTime);
     }


    if(GetKeyDown(VK_ESCAPE))
     {
          Quit();
     }

}

void Engine::Render() //콘솔에서는 렌더링이 std::cout 밖에 없음.goood
{
    if (mainLevel) 
    {
        mainLevel->Render();
    }
}
