#include "RS_Input.h"

void RS_Input::Update()
{
	while (SDL_PollEvent(&inputEvent)) {
		if (inputEvent.type == SDL_KEYDOWN && inputEvent.key.repeat == NULL) {
			/*if (inputEvent.key.keysym.sym == SDLK_w || inputEvent.key.keysym.sym == SDLK_UP) {
				DispatchActionEvent(moveVListeners, { InputAction::MoveV, ActionState::Pressed, -1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_s || inputEvent.key.keysym.sym == SDLK_DOWN) {
				DispatchActionEvent(moveVListeners, { InputAction::MoveV, ActionState::Pressed, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_a || inputEvent.key.keysym.sym == SDLK_LEFT) {
				DispatchActionEvent(moveHListeners, { InputAction::MoveH, ActionState::Pressed, -1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_d || inputEvent.key.keysym.sym == SDLK_RIGHT) {
				DispatchActionEvent(moveHListeners, { InputAction::MoveH, ActionState::Pressed, 1.0f });
			}*/
			/*if (inputEvent.key.keysym.sym == SDLK_SPACE) {
				DispatchActionEvent(shootListeners, { InputAction::Shoot, ActionState::Pressed, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_p) {
				DispatchActionEvent(pauseListeners, { InputAction::Pause, ActionState::Pressed, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_ESCAPE) {
				DispatchActionEvent(exitListeners, { InputAction::Exit, ActionState::Pressed, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_m) {
				DispatchActionEvent(soundListeners, { InputAction::Sound, ActionState::Pressed, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_k) {
				DispatchActionEvent(fullSListeners, { InputAction::Fullscreen, ActionState::Pressed, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_RETURN) {
				DispatchActionEvent(enterKeyListeners, { InputAction::Enter_Key, ActionState::Pressed, 1.0f });
			}*/
			keys[inputEvent.key.keysym.sym] = true;

			log->Log("Key pressed: " + std::string(SDL_GetKeyName(inputEvent.key.keysym.sym)));
		}

		/*if (inputEvent.type == SDL_KEYDOWN && inputEvent.key.repeat) {
			keys[inputEvent.key.keysym.sym] = true;

			if (inputEvent.key.keysym.sym == SDLK_w || inputEvent.key.keysym.sym == SDLK_UP) {
				DispatchActionEvent(moveVListeners, { InputAction::MoveV, ActionState::Hold, -1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_s || inputEvent.key.keysym.sym == SDLK_DOWN) {
				DispatchActionEvent(moveVListeners, { InputAction::MoveV, ActionState::Hold, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_a || inputEvent.key.keysym.sym == SDLK_LEFT) {
				DispatchActionEvent(moveHListeners, { InputAction::MoveH, ActionState::Hold, -1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_d || inputEvent.key.keysym.sym == SDLK_RIGHT) {
				DispatchActionEvent(moveHListeners, { InputAction::MoveH, ActionState::Hold, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_SPACE) {
				DispatchActionEvent(shootListeners, { InputAction::Shoot, ActionState::Hold, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_p) {
				DispatchActionEvent(pauseListeners, { InputAction::Pause, ActionState::Hold, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_ESCAPE) {
				DispatchActionEvent(exitListeners, { InputAction::Exit, ActionState::Hold, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_m) {
				DispatchActionEvent(soundListeners, { InputAction::Sound, ActionState::Hold, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_k) {
				DispatchActionEvent(fullSListeners, { InputAction::Fullscreen, ActionState::Hold, 1.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_RETURN) {
				DispatchActionEvent(enterKeyListeners, { InputAction::Enter_Key, ActionState::Hold, 1.0f });
			}
		}*/

		if (inputEvent.type == SDL_KEYUP && inputEvent.key.repeat == NULL) {
			/*if (inputEvent.key.keysym.sym == SDLK_w || inputEvent.key.keysym.sym == SDLK_UP) {
				DispatchActionEvent(moveVListeners, { InputAction::MoveV, ActionState::Released, 0.0f });

			}
			if (inputEvent.key.keysym.sym == SDLK_s || inputEvent.key.keysym.sym == SDLK_DOWN) {
				DispatchActionEvent(moveVListeners, { InputAction::MoveV, ActionState::Released, 0.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_a || inputEvent.key.keysym.sym == SDLK_LEFT) {
				DispatchActionEvent(moveHListeners, { InputAction::MoveH, ActionState::Released, 0.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_d || inputEvent.key.keysym.sym == SDLK_RIGHT) {
				DispatchActionEvent(moveHListeners, { InputAction::MoveH, ActionState::Released, 0.0f });
			}*/
			if (inputEvent.key.keysym.sym == SDLK_SPACE) {
				DispatchActionEvent(shootListeners, { InputAction::Shoot, ActionState::Released, 0.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_p) {
				DispatchActionEvent(pauseListeners, { InputAction::Pause, ActionState::Released, 0.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_ESCAPE) {
				DispatchActionEvent(exitListeners, { InputAction::Exit, ActionState::Released, 0.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_m) {
				DispatchActionEvent(soundListeners, { InputAction::Sound, ActionState::Released, 0.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_k) {
				DispatchActionEvent(fullSListeners, { InputAction::Fullscreen, ActionState::Released, 0.0f });
			}
			if (inputEvent.key.keysym.sym == SDLK_RETURN) {
				DispatchActionEvent(enterKeyListeners, { InputAction::Enter_Key, ActionState::Released, 0.0f });
			}

			keys[inputEvent.key.keysym.sym] = false;

			log->Log("Key released: " + std::string(SDL_GetKeyName(inputEvent.key.keysym.sym)));
		}
	}
}

bool RS_Input::IsKeyPressed(char key)
{
	return keys[key];
}

void RS_Input::BindInputAction(RS_InputActionListener* listener, InputAction action)
{
	switch (action) {
	case InputAction::MoveV:
		moveVListeners.push_back(listener);
		break;
	case InputAction::MoveH:
		moveHListeners.push_back(listener);
		break;
	case InputAction::Shoot:
		shootListeners.push_back(listener);
		break;
	case InputAction::Pause:
		pauseListeners.push_back(listener);
		break;
	case InputAction::Exit:
		exitListeners.push_back(listener);
		break;
	case InputAction::Fullscreen:
		fullSListeners.push_back(listener);
		break;
	case InputAction::Sound:
		soundListeners.push_back(listener);
		break;
	case InputAction::Enter_Key:
		enterKeyListeners.push_back(listener);
		break;
	}
	listener->eventId = eventNumber++;
}

void RS_Input::UnbindInputAction(RS_InputActionListener* listener, InputAction action)
{
	switch (action) {
	case InputAction::MoveV:
		UnbindInputAction(moveVListeners, listener);
		break;
	case InputAction::MoveH:
		UnbindInputAction(moveHListeners, listener);
		break;
	case InputAction::Shoot:
		UnbindInputAction(shootListeners, listener);
		break;
	case InputAction::Pause:
		UnbindInputAction(pauseListeners, listener);
		break;
	case InputAction::Exit:
		UnbindInputAction(exitListeners, listener);
		break;
	case InputAction::Fullscreen:
		UnbindInputAction(fullSListeners, listener);
		break;
	case InputAction::Sound:
		UnbindInputAction(soundListeners, listener);
		break;
	case InputAction::Enter_Key:
		UnbindInputAction(enterKeyListeners, listener);
		break;
	}
}

void RS_Input::DispatchActionEvent(std::vector<RS_InputActionListener*> list, ActionData data)
{
	for (std::vector<RS_InputActionListener*>::iterator l = list.begin(); l != list.end(); ++l)
	{
		(*l)->HandleEvent(data);
	}
}

void RS_Input::UnbindInputAction(std::vector<RS_InputActionListener*> list, RS_InputActionListener* listener)
{
	int index = -1;
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->eventId == listener->eventId) {
			index = i;
			break;
		}
	}

	list.erase(list.begin() + index);
}
