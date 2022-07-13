#include "RS_TextureManager.h"

RS_TextureManager::~RS_TextureManager()
{
	for (auto&& tex : textures) {
		delete(tex);
	}
}

RS_Texture& RS_TextureManager::GetTexture(const char* name)
{
	for (auto&& tex : textures) {
		if (tex->GetName().compare(name) == 0) {
			return *tex;
		}
	}

	return *textures[0];
}

void RS_TextureManager::LoadTexture(SDL_Renderer* renderer, const char* name, const char* file)
{
	SDL_Surface* surface = IMG_Load(file);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect rect;
	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

	//log->Log("Texture width: " + std::to_string(rect.w) + ", height: " + std::to_string(rect.h));

	textures.push_back(new RS_Texture(name, texture, rect.w, rect.h));
	SDL_FreeSurface(surface);
}