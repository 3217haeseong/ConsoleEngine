#include "Actor.h"
#include <Windows.h>
#include <iostream>

Actor::Actor(const char image, Color color) : image(image), color(color)
{

}
Actor::~Actor()
{

}

// 이벤트 함수. 

// 객체 생애주기(Lifetime)에 1번만 호출됨 (초기화 목적).
void Actor::BeginPlay()
{
	hasBeganPlay = true;
}

// 프레임마다 호출 (반복성 작업/ 지속성이 필요한 작업).
void Actor::Tick(float deltaTime)
{

}

// 그리기 함수. 
void Actor::Render()
{
	// 콘솔 출력을 제어하는 핸들 얻어오기.
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// 커서 위치 값 생성.
	COORD coord;
	coord.X = (short)position.x;
	coord.Y = (short)position.y;

	// 커서 이동.
	SetConsoleCursorPosition(handle, coord);

	// 색상 설정.
	SetConsoleTextAttribute(handle, (WORD)color);

	std::cout << image;

}

void Actor::SetPosition(const Vector2& newPosition)
{
	// 콘솔 출력을 제어하는 핸들 얻어오기.
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// 커서 위치 값 생성.
	COORD coord;
	coord.X = (short)position.x;
	coord.Y = (short)position.y;

	// 커서 이동.
	SetConsoleCursorPosition(handle, coord);

	std::cout << ' ';

	position = newPosition;
}

Vector2 Actor::Position() const
{
	return position;
}


