#include "TimeManager.h"
#include "Lediri.h"

TimeManager* TimeManager::ptrInstance = nullptr;

void TimeManager::privProcessTime(float sys_time)
{
	previousTime = currentTime;
	currentTime = FrzTime.GetTimeInSeconds(sys_time);
	frameTime = currentTime - previousTime;
}

float TimeManager::privGetGameTime()
{
	return currentTime;
}

float TimeManager::privGetLastFrameTime()
{
	return frameTime;
}

void TimeManager::privDeleteTimeManager()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}