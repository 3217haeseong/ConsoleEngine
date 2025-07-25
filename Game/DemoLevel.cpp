#include "DemoLevel.h"
#include "TestActor.h"

DemoLevel::DemoLevel()
{
	TestActor* actor = new TestActor();
	AddActor(actor);
}