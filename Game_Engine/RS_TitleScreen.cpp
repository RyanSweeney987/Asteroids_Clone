#include "RS_TitleScreen.h"
#include "RS_WindowController.h"
#include "RS_Background.h"


RS_TitleScreen::RS_TitleScreen() : RS_GameWorld()
{
}

void RS_TitleScreen::Init()
{
	RS_WindowController& cont = RS_WindowController::GetInstance();
	SDL_Window* window = cont.GetWindow();
	SDL_Renderer* renderer = cont.GetRenderer();

	if (window == NULL || renderer == NULL) {
		printf("What!?");
	}

	unsigned int halfWidth = cont.GetWindowWidth() / 2;
	unsigned int halfHeight = cont.GetWindowHeight() / 2;

	textureManager->LoadTexture(renderer, "bg", "content/sprites/Background.png");
	RS_Sprite* sprite = new RS_Sprite(textureManager->GetTexture("bg"), 1, 1);

	RS_GameObject* gameObject = new RS_Background(*sprite);

	ScreenText* controlsV = new ScreenText(window, "content/fonts/Roboto-Regular.ttf");
	controlsV->setText("W, S to move vertically", halfWidth, halfHeight - 80, true, 32, 255, 255, 255);
	textObjects.push_back(controlsV);

	ScreenText* controlsH = new ScreenText(window, "content/fonts/Roboto-Regular.ttf");
	controlsH->setText("A, D to move horizontally", halfWidth, halfHeight - 40, true, 32, 255, 255, 255);
	textObjects.push_back(controlsH);

	ScreenText* toggleFullS = new ScreenText(window, "content/fonts/Roboto-Regular.ttf");
	toggleFullS->setText("K to toggle fullscreen", halfWidth, halfHeight, true, 32, 255, 255, 255);
	textObjects.push_back(toggleFullS);

	ScreenText* toggleSound = new ScreenText(window, "content/fonts/Roboto-Regular.ttf");
	toggleSound->setText("M to toggle music", halfWidth, halfHeight + 40, true, 32, 255, 255, 255);
	textObjects.push_back(toggleSound);

	ScreenText* text = new ScreenText(window, "content/fonts/Roboto-Regular.ttf");
	text->setText("Press Enter to Continue", halfWidth, halfHeight + 140, true, 48, 255, 255, 255);
	textObjects.push_back(text);

	soundManager->LoadSound("music_1", "content/audio/music/bensound-goinghigher.wav", 255, 0, SoundType::Track);
	RS_Sound* sound = &soundManager->GetSound("music_1");
	sound->Play();

	input->BindInputAction(this, InputAction::Enter_Key);
	input->BindInputAction(this, InputAction::Fullscreen);
	input->BindInputAction(this, InputAction::Sound);
}

void RS_TitleScreen::Update()
{
}

void RS_TitleScreen::Input()
{
	/*if (input->IsKeyPressed(SDLK_k)) {
		RS_WindowController& winCont = RS_WindowController::GetInstance();
		winCont.SetFullscreenMode(!winCont.IsFullscreen());
	}
	if (input->IsKeyPressed(SDLK_RETURN)) {
		Stop();
	}
	if(input->IsKeyPressed())*/
}

void RS_TitleScreen::HandleEvent(ActionData data)
{
	RS_GameWorld::HandleEvent(data);
}

void RS_TitleScreen::HandleEvent(ActionData data, int id)
{
	RS_GameWorld::HandleEvent(data);

}
