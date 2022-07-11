#include "RS_GameWorld.h"
#include "RS_Rectangle.h"

RS_GameWorld::RS_GameWorld()
{
}

RS_GameWorld::~RS_GameWorld()
{
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
