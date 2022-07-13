#include "RS_MainGame.h"
#include "RS_WindowController.h"
#include "RS_Asteroid.h"

RS_MainGame::RS_MainGame(): RS_GameWorld()
{

}

void RS_MainGame::Init()
{
	log->Log("Starting main game");

	SDL_Window* window = RS_WindowController::GetInstance().GetWindow();
	SDL_Renderer* renderer = RS_WindowController::GetInstance().GetRenderer();

	//textureManager->LoadTexture(renderer, "ship", "content/sprites/Ship_Debug.png");
	textureManager->LoadTexture(renderer, "ship", "content/sprites/Ship.png");

	textureManager->LoadTexture(renderer, "asteroid", "content/sprites/Asteroid_1.png");
	/*textureManager->LoadTexture(renderer, "asteroid", "content/sprites/Asteroid_1.png");
	textureManager->LoadTexture(renderer, "enemy", "content/sprites/EnemyShip.png");
	textureManager->LoadTexture(renderer, "bullets", "content/sprites/Bullets.png");
	textureManager->LoadTexture(renderer, "explosion", "content/sprites/Explosion.png");*/

	/*SDL_Texture* texture = textureManager->GetTexture("ship").GetTextureData();

	RS_Texture* tex = new RS_Texture("shipTexture", texture, 250, 250);*/

	RS_Sprite* sprite = new RS_Sprite(textureManager->GetTexture("ship"), 5, 1);

	RS_AnimationSequence* idleSequence = new RS_AnimationSequence();
	idleSequence->SetLoopCount(-1);
	idleSequence->AddAnimationFrames(*new RS_AnimationFrame(0, 0));
	idleSequence->AddAnimationFrames(*new RS_AnimationFrame(1, 0));

	RS_AnimationSequence* moveSeq = new RS_AnimationSequence();
	moveSeq->SetLoopCount(0);
	moveSeq->AddAnimationFrames(*new RS_AnimationFrame(2, 0));

	sprite->AddAnimationSequence(idleSequence);
	sprite->AddAnimationSequence(moveSeq);

	RS_Player* player = new RS_Player(0, 0, 32, 32, *sprite);
	RS_Collider* collider = &player->GetCollider();
	collider->GetCollisionBox().x = 16;
	collider->GetCollisionBox().y = 16;
	collider->GetCollisionBox().w = 32;
	collider->GetCollisionBox().h = 32;
	//collider->SetDebugRenderEnabled(true);
	gameObjects.push_back(player);

	int halfWidth = RS_WindowController::GetInstance().GetWindowWidth() / 2;
	int halfHeight = RS_WindowController::GetInstance().GetWindowHeight() / 2;

	player->GetTransform().MoveTo(RS_Vector2(halfWidth - (player->GetSprite().GetSpriteBounds().w / 2), halfHeight - (player->GetSprite().GetSpriteBounds().h / 2)));

	InitAsteroids();

	gameEvents = new SDL_Event();

	timer.AddCallbackFunction(&countDown);

	countDownText = new ScreenText(window, "content/fonts/Roboto-Bold.ttf", 18);
	countDownText->setText("Countdown: 30", halfWidth - 100, 40, true, 18, 255, 255, 255);
	textObjects.push_back(countDownText);

	scoreText = new ScreenText(window, "content/fonts/Roboto-Bold.ttf", 18);
	scoreText->setText("Score: 0", halfWidth + 100, 40, true, 18, 255, 255, 255);
	textObjects.push_back(scoreText);

	log->Log("Starting main game loop");
}

void RS_MainGame::Update()
{
	log->Log("Updating main game loop");
	RS_GameWorld::Update();

	if (!timer.HasStarted()) {
		timer.StartTimer();
	}
	
	if (!timer.HasFinished()) {
		timer.Update();

		if (countDown.timerCount < 0) {
			countDown.timerCount = 0;
			timer.StopTimer();
		}
	}

	std::stringstream timestr;

	timestr << "Countdown: " << countDown.timerCount;

	int halfWidth = RS_WindowController::GetInstance().GetWindowWidth() / 2;

	countDownText->setText(timestr.str());
	//scoreText->setText("Score: 0", halfWidth + 100, 40, true, 18, 255, 255, 255);


	if (countDown.timerCount == 0) {
		// Game over
		Stop();
	}
}

void RS_MainGame::Input()
{
	
}

void RS_MainGame::HandleEvent(ActionData data)
{
	RS_GameWorld::HandleEvent(data);
}

void RS_MainGame::HandleEvent(ActionData data, int id)
{
	RS_GameWorld::HandleEvent(data, id);
}

void RS_MainGame::InitAsteroids()
{
	for (int i = 0; i < 20; i++) {
		RS_Sprite* astSprite = new RS_Sprite(textureManager->GetTexture("asteroid"), 1, 1);
		RS_Asteroid* asteroid = new RS_Asteroid(0, 0, 64, 64, *astSprite);

		RS_Collider* astCollider = &asteroid->GetCollider();
		astCollider->GetCollisionBox().x = 8;
		astCollider->GetCollisionBox().y = 8;
		astCollider->GetCollisionBox().w = 56;
		astCollider->GetCollisionBox().h = 56;
		//astCollider->SetDebugRenderEnabled(true);

		int x = rand() % 1280;
		int y = rand() % 720;
		asteroid->GetTransform().MoveTo(RS_Vector2f(x, y));

		gameObjects.push_back(asteroid);
	}

}

void CountDownTimer::Run()
{
	timerCount -= 1;
	if (timerCount < 0) {
		timerCount = 0;
	}
}
