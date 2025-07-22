#include "Engine.h"
#include<iostream>

//2���� ��� �߰�
// ��������
//�ܼ� �Է� ó�� (Ű����).
//Ÿ�̸�(�ð� ���).

Engine::Engine()
{
}

Engine::~Engine()
{
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
            Update(deltaTime);
            Render();

            //�ð� ������Ʈ
            previousTime = currentTime;
        }


    }

}

void Engine::Quit()
{
    //���� �÷��� ����
    isQuit = true;
}

void Engine::ProcessInput()
{
    //Esc Ű ���� Ȯ��{
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        //����
        Quit();
    }
}

void Engine::Update(float deltaTime)
{
    std::cout << "DeltaTime:" << deltaTime << ",FPS: " <<(1.0f/deltaTime) << "\n";  // fps �� ���� Ÿ��
}

void Engine::Render() //�ֿܼ����� �������� std::cout �ۿ� ����.goood
{
}
