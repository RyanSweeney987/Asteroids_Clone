#include "RS_GameWorld.h"
<<<<<<< Updated upstream
#include "RS_Rectangle.h"

RS_GameWorld::RS_GameWorld()
{
=======
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

>>>>>>> Stashed changes
}

RS_GameWorld::~RS_GameWorld()
{
<<<<<<< Updated upstream
	delete inputEvent;

	for (RS_Shape* shape : shapes) {
		delete shape;
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void RS_GameWorld::start()
{
	time.resetChronoTimer();

	window = SDL_CreateWindow("Test Window", 250, 250, 1280, 720, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	inputEvent = new SDL_Event();

	/*RS_Rectangle* rect = new RS_Rectangle(RS_Vector2(500, 500), 200);
	rect->update();
		
	auto lambda = [=]() {
		if (keys[SDLK_w]) {
			rect->getTransform().move(RS_Vector2(-1, 0));
		}
	};*/

	shapes.push_back(new RS_Rectangle(RS_Vector2(200, 200), 200));
	shapes.push_back(new RS_Rectangle(RS_Vector2(500, 700), 50));

	isRunning = true;

	run();
}

void RS_GameWorld::run()
{
	while (isRunning) {
		time.resetChronoTimer();

		input();
		update();
		draw();

		if (time.getChronoTime() < DELTA_TIME) {
			SDL_Delay(DELTA_TIME - time.getChronoTime());
		}
	}
}

void RS_GameWorld::stop()
{
	// Cleanup
}

void RS_GameWorld::update()
{
	if (keys[SDLK_w]) {
		shapes[0]->getPosition() += RS_Vector2(0, -1);
		keys[SDLK_w] = false;
	}
	if (keys[SDLK_a]) {
		shapes[0]->getPosition() += RS_Vector2(-1, 0);
		keys[SDLK_a] = false;
	}
	if (keys[SDLK_s]) {
		shapes[0]->getPosition() += RS_Vector2(0, 1);
		keys[SDLK_s] = false;
	}
	if (keys[SDLK_d]) {
		shapes[0]->getPosition() += RS_Vector2(1, 0);
		keys[SDLK_d] = false;
	}
}

void RS_GameWorld::input()
{
	while (SDL_PollEvent(inputEvent)) {
		if (inputEvent->type == SDL_QUIT) {
			isRunning = false;
		}

		if (inputEvent->type == SDL_KEYDOWN && inputEvent->key.repeat == NULL) {
			switch (inputEvent->key.keysym.sym) {
			case SDLK_ESCAPE:
				isRunning = false;
				break;
			case SDLK_w:
				SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Key pressed - w");
				keys[SDLK_w] = true;
				break;
			case SDLK_a:
				SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Key pressed - a");
				keys[SDLK_a] = true;
				break;
			case SDLK_s:
				SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Key pressed - s");
				keys[SDLK_s] = true;
				break;
			case SDLK_d:
				SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Key pressed - d");
				keys[SDLK_d] = true;
				break;
			}
		}

		if (inputEvent->type == SDL_KEYUP && inputEvent->key.repeat == NULL) {
			switch (inputEvent->key.keysym.sym) {
			case SDLK_ESCAPE:
				isRunning = false;
				break;
			case SDLK_w:
				keys[SDLK_w] = false;
				break;
			case SDLK_a:
				SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Key pressed - a");
				keys[SDLK_a] = false;
				break;
			case SDLK_s:
				SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Key pressed - s");
				keys[SDLK_s] = false;
				break;
			case SDLK_d:
				SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Key pressed - d");
				keys[SDLK_d] = false;
				break;
			}
		}
	}
}

void RS_GameWorld::draw()
{
	// Set background colour
	//SDL_SetRenderDrawColor(renderer, 33, 33, 33, 255);
	//// Clear window

	//SDL_Rect r;
	//r.x = 50;
	//r.y = 50;
	//r.w = 50;
	//r.h = 50;
	//// Set rect colour
	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//// Draw rect
	//SDL_RenderFillRect(renderer, &r);

	//SDL_Point triangle[4] = {
	//	{ 200, 50 },
	//	{ 250, 50 },
	//	{ 225, 100 },
	//	{ 200, 50 }
	//};
	//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);


	//// Render rect to screen
	//SDL_RenderPresent(renderer);

	SDL_SetRenderDrawColor(renderer, 33, 33, 33, 255);
	SDL_RenderClear(renderer);

	for (RS_Shape* shape : shapes) {

		if (shape->getType() == "triangle") {

		}
		else if (shape->getType() == "rectangle") {
			SDL_Point points[5] = {
				{shape->getPoints()[0].x + shape->getPosition().x, shape->getPoints()[0].y + shape->getPosition().y},
				{shape->getPoints()[1].x + shape->getPosition().x, shape->getPoints()[1].y + shape->getPosition().y},
				{shape->getPoints()[2].x + shape->getPosition().x, shape->getPoints()[2].y + shape->getPosition().y},
				{shape->getPoints()[3].x + shape->getPosition().x, shape->getPoints()[3].y + shape->getPosition().y},
				{shape->getPoints()[4].x + shape->getPosition().x, shape->getPoints()[4].y + shape->getPosition().y},
			};

			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderDrawLines(renderer, points, shape->getPointsCount());
		}
		else if (shape->getType() == "point") {

		}
	}

	SDL_RenderPresent(renderer);
}

bool RS_GameWorld::getIsRunning()
{
	return isRunning;
}
=======
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
>>>>>>> Stashed changes
