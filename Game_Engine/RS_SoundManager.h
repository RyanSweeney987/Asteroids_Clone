#pragma once
#include "RS_Sound.h"
#include "RS_Logger.h"
#include <vector>

enum SoundType
{
	Track,
	Clip
};

class RS_SoundManager {
public:
	static RS_SoundManager& GetInstance()
	{
		static RS_SoundManager instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}
	RS_SoundManager(RS_SoundManager const&) = delete;
	void operator=(RS_SoundManager const&) = delete;

	RS_Sound& GetSound(const char* name);
	void LoadSound(const char* name, const char* file, unsigned int volume, int channel, SoundType type);
private:
	RS_SoundManager() {
		log = &RS_Logger::GetInstance();
	};

	RS_Logger* log;
	std::vector<RS_Sound*> sounds;
};