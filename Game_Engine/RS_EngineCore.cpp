#include "RS_EngineCore.h"
#include "RS_TitleScreen.h"
#include "RS_MainGame.h"
#include "RS_WindowController.h"

RS_EngineCore::RS_EngineCore()
{
	log = &RS_Logger::GetInstance();
}

RS_EngineCore::~RS_EngineCore()
{
	RS_WindowController::GetInstance().DestroyWindow();

	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

void RS_EngineCore::Start()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		log->Log(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_CRITICAL, "SDL failed to initialise");
	}
	if (IMG_Init(SDL_INIT_EVERYTHING) < 0) {
		log->Log(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_CRITICAL, "SDL_IMG failed to initialise");
	}
		 
	RS_Input::GetInstance();
	RS_SoundManager::GetInstance();
	RS_WindowController::GetInstance();

	RS_WindowController::GetInstance().CreateWindow("CGP2015M Game Programming - Ryan Sweeney - 18681877 - Asteroidslite", 1280, 720);
	RS_WindowController::GetInstance().CreateRenderer(RS_WindowController::GetInstance().GetWindow());

	// Default texture
	RS_TextureManager::GetInstance().LoadTexture(RS_WindowController::GetInstance().GetRenderer(), "default", "content/sprites/default.png");

	Run();
}

void RS_EngineCore::Run()
{
	// Start spash screen
	RS_TitleScreen title;
	title.Start();
	// Main game
	RS_MainGame game;
	game.Start();
}