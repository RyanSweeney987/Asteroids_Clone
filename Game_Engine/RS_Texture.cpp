#include "RS_Texture.h"

RS_Texture::RS_Texture(std::string name, SDL_Texture* texture, unsigned int width, unsigned int height) : name(name), texture(texture), width(width), height(height)
{

}

RS_Texture::~RS_Texture()
{
	SDL_DestroyTexture(texture);
}

std::string RS_Texture::GetName()
{
	return name;
}

unsigned int RS_Texture::GetWidth()
{
	return width;
}

unsigned int RS_Texture::GetHeight()
{
	return height;
}

SDL_Texture* RS_Texture::GetTextureData()
{
	return texture;
}
