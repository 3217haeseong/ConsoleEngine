#pragma once

#include "TestActor.h"
#include "../Engine/Actor/Actor.h"

class TestActor : public Actor
{
	RTTI_DECLARATIONS(TestActor, Actor)

public:
	TestActor();
	void Tick(float deltaTime);
};
