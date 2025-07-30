#pragma once

#include "Level/Level.h"
#include "Interface/ICanPlayerMove.h"

class SokobanLevel : public Level, public ICanPlayerMove
{
	RTTI_DECLARATIONS(SokobanLevel, Level);

public:
	SokobanLevel();

	virtual void Render() override;

public:
	// ICanPlayerMove을(를) 통해 상속됨
	virtual bool CanPlayerMove(const Vector2& playerPosition, const Vector2& newPosition) override;

private:
	// 맵 파일을 읽어서 게임 객체 생성하는 함수.
	void ReadMapFile(const char* filename);

	// 게임 클리어 확인하는 함수.
	bool CheckGameClear();


private:
	int targetScore = 0;
	bool isGameClear = false;
};