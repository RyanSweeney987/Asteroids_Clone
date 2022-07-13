#include "RS_Time.h"

void RS_Time::startChronoTimer()
{
	resetChronoTimer();
}

void RS_Time::resetChronoTimer()
{
	startChrono = Clock::now();
}

float RS_Time::getChronoTime()
{
	std::chrono::steady_clock::time_point now = Clock::now();
	auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(now - startChrono).count();
	return (float)timeDiff;
}

std::string RS_Time::getCurrentDateTime()
{
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	std::string s(30, '\0');
	std::tm bt{};
#if defined(__unix__)
	localtime_r(&now, &bt);
	std::strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", &bt);
#else
	localtime_s(&bt, &now);
	std::strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", &bt);
#endif
	return s;
}
