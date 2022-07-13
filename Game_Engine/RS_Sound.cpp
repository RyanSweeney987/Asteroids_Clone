#include "RS_Sound.h"

RS_Sound::RS_Sound(std::string name, unsigned int volume, int channel) : name(name), volume(volume), channel(channel)
{
}

RS_Sound::~RS_Sound()
{
}

unsigned int RS_Sound::GetVolume()
{
	return volume;
}

int RS_Sound::GetChannel()
{
	return channel;
}

std::string RS_Sound::GetName()
{
	return name;
}

void RS_Sound::SetVolume(unsigned int volume)
{
	volume = volume > 255 ? 255 : volume;
}

void RS_Sound::SetChannel(int channel)
{
	channel = channel;
}

RS_SoundClip::RS_SoundClip(std::string name, unsigned int volume, int channel, Mix_Chunk* clip): RS_Sound(name, volume, channel), clip(clip)
{
	Mix_VolumeChunk(clip, volume);
}

RS_SoundClip::~RS_SoundClip()
{
	Mix_FreeChunk(clip);
}

void RS_SoundClip::SetVolume(unsigned int volume)
{
	RS_Sound::SetVolume(volume);

	Mix_VolumeChunk(clip, volume);
}

void RS_SoundClip::Play()
{
	Play(0);
}

void RS_SoundClip::Play(int loops)
{
	Mix_PlayChannel(channel, clip, loops);
}

void RS_SoundClip::Stop()
{
	Mix_HaltChannel(channel);
}

void RS_SoundClip::Pause()
{
	Mix_Pause(channel);
}

RS_SoundTrack::RS_SoundTrack(std::string name, unsigned int volume, Mix_Music* track) : RS_Sound(name, volume, -1), track(track)
{
}

RS_SoundTrack::~RS_SoundTrack()
{
	Mix_FreeMusic(track);
}

void RS_SoundTrack::SetVolume(unsigned int volume)
{
	RS_Sound::SetVolume(volume);
	Mix_VolumeMusic(volume);
}

void RS_SoundTrack::Play()
{
	Play(0);
}

void RS_SoundTrack::Play(int loops)
{
	Mix_PlayMusic(track, loops);
}

void RS_SoundTrack::Stop()
{
	Mix_HaltMusic();
}

void RS_SoundTrack::Pause()
{
	Mix_PauseMusic();
}
