#pragma once
#include <sstream>
#include<fstream>
#include "RS_Time.h"
#include "SDL.h"

class RS_Logger {
public:
	static RS_Logger& GetInstance()
	{
		static RS_Logger instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}
	RS_Logger(RS_Logger const&) = delete;
	void operator=(RS_Logger const&) = delete;

	void Log(std::string message);
	//void Log(const char* messages...);
	void LogError(std::string message);
	void Log(int category, SDL_LogPriority priority, std::string message);
private:
	RS_Logger() {
		time.startChronoTimer();

		logFile.open("game-log.txt");

		if (!logFile.is_open()) {
			Log("Couldn't open log file");
		}

		//SDL_LogSetOutputFunction(&RS_Logger::LogCallback, (void*)this);
	};
	~RS_Logger() {
		logFile.close();
	}

	static void LogCallback(void* userdata, int category, SDL_LogPriority priority, const char* message);

	RS_Time time;
	std::ofstream logFile;
};


