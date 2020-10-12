#ifndef TimeManager_H
#define TimeManager_H

#include "FreezeTime.h"

class TimeManager
{
public:
	static float GetGameTime() { return Instance().privGetGameTime(); };
	static float GetLastFrameTime() { return Instance().privGetLastFrameTime(); };

private:
	
	friend class TimeManagerAttorney;
	TimeManager() = default;
	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;
	~TimeManager() {};

	static TimeManager* ptrInstance;

	static TimeManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new TimeManager;
		}
		return *ptrInstance;
	}
	
	//Attorny-ed methods for Lediri to use
	static void ProcessTime(float sys_time) { Instance().privProcessTime(sys_time); };
	void privProcessTime(float sys_time);
	static void DeleteTimeManager() { Instance().privDeleteTimeManager(); };
	void privDeleteTimeManager();
	float privGetGameTime();
	float privGetLastFrameTime();

	float time;
	float frameTime;
	float previousTime;
	float currentTime;

	FreezeTime FrzTime;
};
#endif // !TimeManager_H
