#pragma once
#include <functional>
#include "RS_Time.h"

class RS_TimerCallback {
public:
	virtual void Run() = 0;
};

class RS_Timer : public RS_Time {
public:
	RS_Timer(float length, bool repeat);

	bool HasStarted();
	bool HasFinished();

	void StartTimer();
	void StopTimer();
	void Update();
	void AddCallbackFunction(RS_TimerCallback* callback);
private:
	float length;
	bool repeat;
	bool hasStarted;
	bool hasFinished;

	RS_TimerCallback* callbackFunction;

	//std::chrono::steady_clock::time_point resumeChrono;
	//std::chrono::steady_clock::time_point pauseChrono;
};
