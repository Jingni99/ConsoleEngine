#pragma once
#pragma warning(disable: 4251)   //dll 외부로 템플릿 내보낼 때 발생하는 경고 비활성화
#pragma warning(disable: 4172)	 //지역변수의 주소를 반환할 때 발생하는 경고 비활성화 


//메모리 누수 확인
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#if BuildEngineDLL
#define Engine_API __declspec(dllexport)
#else
#define Engine_API __declspec(dllimport)
#endif

