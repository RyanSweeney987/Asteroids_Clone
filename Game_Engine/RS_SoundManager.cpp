#include "RS_SoundManager.h"

RS_Sound& RS_SoundManager::GetSound(const char* name)
{
	for (auto&& sound : sounds) {
		if (sound->GetName().compare(name) == 0) {
			return *sound;
		}
	}

	return *sounds[0];
}

void RS_SoundManager::LoadSound(const char* name, const char* file, unsigned int volume = 255, int channel = -1, SoundType type = Track)
{
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		log->Log(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "Failed to open mixer: " + std::string(Mix_GetError()));
	} else {
		switch (type) {
		case Track:
			sounds.push_back(new RS_SoundTrack(name, volume, Mix_LoadMUS(file)));
			break;
		case Clip:
			sounds.push_back(new RS_SoundClip(name, volume, channel, Mix_LoadWAV(file)));
			break;
		}
		/*Mix_VolumeChunk(SOUND_aShot, 128);
		Mix_VolumeMusic(32);*/
	}
}
