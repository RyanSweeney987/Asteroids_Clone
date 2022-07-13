#pragma once
#include <SDL.h>
#include "RS_Logger.h"
#include "RS_Vector2.h"

class RS_WindowController {
public:
	static RS_WindowController& GetInstance()
	{
		static RS_WindowController instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}
	RS_WindowController(RS_WindowController const&) = delete;
	void operator=(RS_WindowController const&) = delete;

	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();

	bool IsFullscreen();
	unsigned int GetWindowWidth();
	unsigned int GetWindowHeight();

	void SetResolution(unsigned int width, unsigned int height);
	void SetFullscreenMode(bool fullscreen);
	
	void CreateWindow(const char* title, unsigned int width, unsigned int height);
	void DestroyWindow();
	void CreateRenderer(SDL_Window* window);
	void DestroyRenderer(SDL_Renderer* renderer);
private:
	RS_WindowController() {
		log = &RS_Logger::GetInstance();
	}

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	std::string title;
	RS_Vector2 windowedDimension = RS_Vector2(1280, 720);
	bool isFullscreen = false;
	
	RS_Logger* log;

	//void UpdateDisplay();
};