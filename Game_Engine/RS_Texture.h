#pragma once
#include <SDL.h>
#include <string>

class RS_Texture {
public: 
	RS_Texture(std::string name, SDL_Texture* texture, unsigned int width, unsigned int height);
	~RS_Texture();

	std::string GetName();
	unsigned int GetWidth();
	unsigned int GetHeight();
	SDL_Texture* GetTextureData();
private:
	std::string name;
	SDL_Texture* texture;
	unsigned int width;
	unsigned int height;
};