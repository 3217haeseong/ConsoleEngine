#include "Input.h"
#include "Windows.h"

Input* Input::instance = nullptr;

Input::Input()
{
	// 싱글톤 실행을 위해 instance 변수 설정.
	instance = this;
}

void Input::ProcessInput()
{
	// 키 입력 확인.
	for (int ix = 0; ix < 255; ++ix)
	{
		keyStates[ix].isKeyDown =
			GetAsyncKeyState(ix) & 0x8000;
	}

}

void Input::SavePreviousKeyStates()
{
	// 현재 프레임의 입력을 기록.
	for (int ix = 0; ix < 255; ++ix)
	{
		keyStates[ix].previousKeyDown = keyStates[ix].isKeyDown;
	}
}

bool Input::GetKey(int keyCode)
{

	return keyStates[keyCode].isKeyDown;
}

bool Input::GetKeyDown(int keyCode)
{
	return !keyStates[keyCode].previousKeyDown
		&& keyStates[keyCode].isKeyDown;
}

bool Input::GetKeyUp(int keyCode)
{
	return keyStates[keyCode].previousKeyDown
		&& !keyStates[keyCode].isKeyDown;
}

Input& Input::Get()
{
	return *instance;
}