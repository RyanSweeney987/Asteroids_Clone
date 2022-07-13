#pragma once

#include <chrono>
#include <string>
#include <time.h>
#include <ctime>

// Credit to Olivier Szymanezyk for code
class RS_Time {
public:
	void startChronoTimer();
	void resetChronoTimer();
	float getChronoTime();
	std::string getCurrentDateTime();
private:
	typedef std::chrono::high_resolution_clock Clock;
	std::chrono::steady_clock::time_point startChrono;
};