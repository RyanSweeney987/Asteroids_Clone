#include "RS_Time.h"

void RS_Time::resetChronoTimer()
{
	startChrono = Clock::now();
}

float RS_Time::getChronoTime()
{
	std::chrono::steady_clock::time_point now = Clock::now(); 
	auto timeDiff = std::chrono::duration_cast<std::chrono::nanoseconds>(now - startChrono).count();
	return (float)timeDiff;
}
