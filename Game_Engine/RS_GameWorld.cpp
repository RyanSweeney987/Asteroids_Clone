#include "RS_GameWorld.h"
#include "RS_GameObject.h"
#include <iostream>
#include <SDL_image.h>
#include "RS_TextureManager.h"
#include "RS_WindowController.h"

RS_GameWorld::RS_GameWorld()
{
	log = &RS_Logger::GetInstance();
	input = &RS_Input::GetInstance();
	textureManager = &RS_TextureManager::GetInstance();
	soundManager = &RS_SoundManager::GetInstance();

}

RS_GameWorld::~RS_GameWorld()
{
	log->Log("Destroying game world");

	for (auto&& obj : gameObjects) {
		delete obj;
	}

	for (auto&& text : textObjects) {
		delete text;
	}
}

void RS_GameWorld::Start()
{
	log->Log("Starting game world");

	time.resetChronoTimer();

	isRunning = true;

	Init();
	Run();
}

void RS_GameWorld::Run()
{
	log->Log("Running game world");

	while (isRunning) {
		if (time.getChronoTime() > DELTA_TIME) {
			input->Update();

			solver.CheckForCollisions(gameObjects);

			Input();
			Update();
			Render();

			time.resetChronoTimer();
		}
	}

	log->Log("Game world run loop finished");
}

void RS_GameWorld::Stop()
{
	log->Log("Stopping game world");
	// Cleanup
	isRunning = false;
}

void RS_GameWorld::Update()
{
	for (auto&& obj : gameObjects) {
		obj->Update();
	}
}

void RS_GameWorld::Render()
{
	log->Log("Rendering");

	SDL_Renderer* renderer = RS_WindowController::GetInstance().GetRenderer();
	// Set background colour
	SDL_SetRenderDrawColor(renderer, 33, 33, 33, 255);
	// Clear the window with default colour
	SDL_RenderClear(renderer);

	log->Log("Rendering sprites: " + std::to_string(gameObjects.size()));
	// Render game objects
	for (auto&& objs : gameObjects) {
		if (objs->GetSprite().IsRenderEnabled()) {
			// Set the position based on the transform
			SDL_Rect pos = objs->GetSprite().GetSize();
			RS_Transform trans = *&objs->GetTransform();
			pos.x = trans.position.x;
			pos.y = trans.position.y;
			pos.w = pos.w * trans.scale.x;
			pos.h = pos.h * trans.scale.y;

			SDL_RenderCopyEx(renderer, objs->GetSprite().GetTexture().GetTextureData(), &objs->GetSprite().GetSpriteBounds(), &pos, trans.angleDeg, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
		}

		if (objs->GetCollider().IsDebugRenderEnabled()) {
			if (objs->GetCollider().IsColliding()) {
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			}
			else {
				SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			}

			SDL_Rect pos = objs->GetCollider().GetCollisionBox();
			RS_Transform trans = *&objs->GetTransform();
			pos.x = pos.x + trans.position.x;
			pos.y = pos.y + trans.position.y;
			pos.w = pos.w * trans.scale.x;
			pos.h = pos.h * trans.scale.y;

			SDL_RenderDrawRect(renderer, &pos);
		}
	}

	log->Log("Rendering text: " + std::to_string(textObjects.size()));
	// Render text
	for (auto&& text : textObjects) {
		text->render();
	}
	
	// Render results onto screen
	SDL_RenderPresent(renderer);
}

bool RS_GameWorld::GetIsRunning()
{
	return isRunning;
}

void RS_GameWorld::HandleEvent(ActionData data)
{
	// Global input actions regardless of game world
	if (data.state == ActionState::Released) {
		RS_WindowController& winCont = RS_WindowController::GetInstance();
		switch (data.action) {
		case InputAction::Enter_Key:
			Stop();
			break;
		case InputAction::Fullscreen:
			winCont.SetFullscreenMode(!winCont.IsFullscreen());
			break;
		case InputAction::Sound:
			if (RS_SoundManager::GetInstance().GetSound("music_1").GetVolume() != 0) {
				RS_SoundManager::GetInstance().GetSound("music_1").SetVolume(0);
			}
			else {
				RS_SoundManager::GetInstance().GetSound("music_1").SetVolume(255);
			}
			break;
		}
	}
}

void RS_GameWorld::HandleEvent(ActionData data, int id)
{
}
