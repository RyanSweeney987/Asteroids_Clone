#pragma once

#include <chrono>

// Credit to Olivier Szymanezyk for code
class RS_Time {
public:       
	void resetChronoTimer(); 
	float getChronoTime();
private:
	typedef std::chrono::high_resolution_clock Clock;        
	std::chrono::steady_clock::time_point startChrono; 
};