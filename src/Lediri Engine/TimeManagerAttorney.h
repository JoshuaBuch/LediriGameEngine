#ifndef TimeManagerAttorney_H
#define TimeManagerAttorney_H

#include "TimeManager.h"

class TimeManagerAttorney
{
public:

private:
	friend class Lediri;

	TimeManagerAttorney() = default;
	TimeManagerAttorney(const TimeManagerAttorney&) = delete;
	TimeManagerAttorney& operator=(const TimeManagerAttorney&) = delete;
	~TimeManagerAttorney() {};

	static void ProcessTime(float sys_time) { TimeManager::ProcessTime(sys_time); };
	static void DeleteTimeManager() { TimeManager::DeleteTimeManager(); };
};
#endif // !TimeManagerAttorney_H
