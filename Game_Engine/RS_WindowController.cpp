
#include "RS_WindowController.h"

SDL_Window* RS_WindowController::GetWindow()
{
	return window;
}

SDL_Renderer* RS_WindowController::GetRenderer()
{
	return renderer;
}

bool RS_WindowController::IsFullscreen()
{
	return isFullscreen;
}

unsigned int RS_WindowController::GetWindowWidth()
{
	return windowedDimension.x;
}

unsigned int RS_WindowController::GetWindowHeight()
{
	return windowedDimension.y;
}

void RS_WindowController::SetResolution(unsigned int width, unsigned int height)
{
}

void RS_WindowController::SetFullscreenMode(bool fullscreen)
{
	isFullscreen = fullscreen;
	if (isFullscreen) {
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
	else {
		SDL_SetWindowFullscreen(window, SDL_WINDOW_SHOWN);

		SDL_SetWindowSize(window, windowedDimension.x, windowedDimension.y);
		SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	}
}

void RS_WindowController::CreateWindow(const char* title, unsigned int width, unsigned int height)
{
	this->title = title;
	windowedDimension.x = width;
	windowedDimension.y = height;

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		// Log error
		log->Log(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "Error creating window: " + std::string(SDL_GetError()));
	}

}

void RS_WindowController::DestroyWindow()
{
	DestroyRenderer(SDL_GetRenderer(window));
	SDL_DestroyWindow(window);
}

void RS_WindowController::CreateRenderer(SDL_Window* window)
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		// Log error
		log->Log(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "Error creating renderer: " + std::string(SDL_GetError()));
	}

	SDL_RenderSetLogicalSize(renderer, 1280, 720);
}

void RS_WindowController::DestroyRenderer(SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
}
