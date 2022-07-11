#pragma once

#include <chrono>
<<<<<<< Updated upstream

// Credit to Olivier Szymanezyk for code
class RS_Time {
public:       
	void resetChronoTimer(); 
	float getChronoTime();
private:
	typedef std::chrono::high_resolution_clock Clock;        
	std::chrono::steady_clock::time_point startChrono; 
=======
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
>>>>>>> Stashed changes
};