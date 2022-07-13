#include "RS_Timer.h"

RS_Timer::RS_Timer(float length, bool repeat = false) : length(length), repeat(repeat)
{
}

bool RS_Timer::HasStarted()
{
	return hasStarted;
}

bool RS_Timer::HasFinished()
{
	return hasFinished;
}

void RS_Timer::StartTimer()
{
	startChronoTimer();
	hasStarted = true;
}

void RS_Timer::StopTimer()
{
	hasFinished = true;
}

void RS_Timer::Update()
{
	if (!hasFinished && getChronoTime() > length) {
		callbackFunction->Run();

		if (repeat) {
			resetChronoTimer();
		}
		else {
			StopTimer();
		}
	}
}

void RS_Timer::AddCallbackFunction(RS_TimerCallback* callback)
{
	callbackFunction = callback;
}
