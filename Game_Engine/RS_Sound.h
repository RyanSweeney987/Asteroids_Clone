#pragma once
#include <string>
#include <SDL_mixer.h>

class RS_Sound {
public:
	RS_Sound(std::string name, unsigned int volume, int channel);
	~RS_Sound();

	virtual void Play() = 0;
	virtual void Play(int loops) = 0;
	virtual void Stop() = 0;
	virtual void Pause() = 0;

	unsigned int GetVolume();
	int GetChannel();
	std::string GetName();

	virtual void SetVolume(unsigned int volume);
	void SetChannel(int channel);

	friend class RS_SoundClip;
	friend class RS_SoundTrack;
private:
	unsigned int volume;
	int channel;
	std::string name;
};

class RS_SoundClip: public RS_Sound {
public:
	RS_SoundClip(std::string name, unsigned int volume, int channel, Mix_Chunk* clip);
	~RS_SoundClip();

	void SetVolume(unsigned int volume) override;

	void Play() override;
	void Play(int loops) override;
	void Stop() override;
	void Pause() override;
private:
	Mix_Chunk* clip = nullptr;
};

class RS_SoundTrack: public RS_Sound {
public:
	RS_SoundTrack(std::string name, unsigned int volume, Mix_Music* track);
	~RS_SoundTrack();

	void SetVolume(unsigned int volume) override;

	void Play() override;
	void Play(int loops) override;
	void Stop() override;
	void Pause() override;
private:
	Mix_Music* track = nullptr;
};