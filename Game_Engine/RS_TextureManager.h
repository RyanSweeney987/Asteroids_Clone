#pragma once
#include "RS_Logger.h"
#include <SDL_image.h>
#include <SDL.h>
#include <vector>
#include <map>
#include "RS_Sprite.h"
#include "RS_Texture.h"

class RS_TextureManager {
public:
	static RS_TextureManager& GetInstance()
	{
		static RS_TextureManager instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}
	RS_TextureManager(RS_TextureManager const&) = delete;
	void operator=(RS_TextureManager const&) = delete;
	~RS_TextureManager();

	RS_Texture& GetTexture(const char* name);
	void LoadTexture(SDL_Renderer* renderer, const char* name, const char* file);
private:
	RS_TextureManager() {
		log = &RS_Logger::GetInstance();
	};

	static RS_TextureManager* instance;

	RS_Logger* log;
	std::vector<RS_Texture*> textures;
};