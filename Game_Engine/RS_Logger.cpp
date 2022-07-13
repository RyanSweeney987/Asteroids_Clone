#include "RS_Logger.h"
#include <iostream>

void RS_Logger::Log(std::string message)
{
	Log(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, message);
}

void RS_Logger::LogError(std::string message)
{
	Log(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, message);
}

void RS_Logger::Log(int category, SDL_LogPriority priority, std::string message)
{
	SDL_LogMessage(category, priority, "[%s] %s", time.getCurrentDateTime().c_str(), message.c_str());

	char buffer[200];
	sprintf_s(buffer, 200, "%s: [%s] %s", std::to_string(priority).c_str(), time.getCurrentDateTime().c_str(), message.c_str());
	logFile << buffer << std::endl;
}

void RS_Logger::LogCallback(void* userdata, int category, SDL_LogPriority priority, const char* message)
{
	RS_Logger* ptr = (RS_Logger*)userdata;
	if (ptr) {
		ptr->Log(message);
	}
}
