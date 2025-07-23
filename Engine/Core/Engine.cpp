#include "Engine.h"
#include<iostream>
#include"Level/Level.h"


//2���� ��� �߰�
// ��������
//�ܼ� �Է� ó�� (Ű����).
//Ÿ�̸�(�ð� ���).

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
    //�ð�����Լ�
   // float currentTime = timeGetTime();
    LARGE_INTEGER currentTime;// 2.Large- INteger��
    LARGE_INTEGER previousTime; //3
    QueryPerformanceCounter(&currentTime);  // 1. �Լ� f12 �� ���� Ȯ�� 
    previousTime = currentTime; //4
    //�����ӽð� ��� .. �и�������� �� ��� 1/1000 ms >> ��

    //�ϵ���� �ð��� ���е�(���ļ�)��������
    //���߿� �ʷ� ��ȯ�ϱ� ����.
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    //** Ÿ�� ������
    float targetFrameRate = 60.0f;

    //** Ÿ�� �� ������ �ð�
    float oneFrameTime = 1.0f / targetFrameRate;

    // GameLoop.
    while (true)
    {
        //���� ���Ῡ�� Ȯ��
        if (isQuit) {
            //���� ����
            break;
        }

        


        //������ �ð� ���
        //(����ð� - �����ð�) / ���ļ�  = �ʴ���.
        QueryPerformanceCounter(&currentTime);

        ////�����ӽð� 1
        //float daltaTime = (currentTime.QuadPart - previousTime.QuadPart) / (float)frequency.QuadPart;
        //** �����ӽð� ���� �ڵ� (������ ���� �ɱ�) - ���� Ÿ�� ������
        float deltaTime = (currentTime.QuadPart - previousTime.QuadPart) / (float)frequency.QuadPart;


        //
        //�Է��� �ִ��� ����
        ProcessInput(); // ���ļ� ���� f9��� Ȯ�� ���ļ��� õ���̸� ����..?
        
        if (deltaTime >= oneFrameTime)
        {
            BeginePlay();
            Tick(deltaTime);
            Render();

            //�ð� ������Ʈ
            previousTime = currentTime;

            //���� �������� �Է��� ���
            for (int ix = 0; ix < 255; ++ix)
            {
                keyStates[ix].previouseKeyDown = keyStates[ix].isKeyDown;  
            }
        }


    }

}

void Engine::AddLevel(Level* newLevel)
{
    //������ �ִ� ���� ����
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
    return !keyStates[keyCode].previouseKeyDown && keyStates[keyCode].isKeyDown;  // true false && ����
}

bool Engine::GetKeyUp(int keyCode)
{
    return keyStates[keyCode].previouseKeyDown && !keyStates[keyCode].isKeyDown;;
}

void Engine::Quit()
{
    //���� �÷��� ����
    isQuit = true;
}

void Engine::ProcessInput()
{
    
    //Ű �Է� Ȯ��
    for(int ix =0 ; ix < 255; ++ix)
    {
        keyStates[ix].isKeyDown = GetAsyncKeyState(ix) & 0x8000;
    }

    ////Esc Ű ���� Ȯ��{
    //if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    //{
    //    //����
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
    //std::cout << "DeltaTime:" << deltaTime << ",FPS: " <<(1.0f/deltaTime) << "\n";  // fps �� ���� Ÿ��
    
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

    //���� ������Ʈ
    if (mainLevel) 
    {
        mainLevel->Tick(deltaTime);
     }


    if(GetKeyDown(VK_ESCAPE))
     {
          Quit();
     }

}

void Engine::Render() //�ֿܼ����� �������� std::cout �ۿ� ����.goood
{
    if (mainLevel) 
    {
        mainLevel->Render();
    }
}
