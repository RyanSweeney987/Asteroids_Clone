#pragma once

#include "SDL.h"
#include "RS_Logger.h"
#include "RS_EventDispatcher.h"
#include <functional>

enum class InputAction {
	MoveV, MoveH, Shoot, Pause, Exit, Fullscreen, Sound, Enter_Key
};

enum class ActionState {
	Pressed, Released, Hold
};

struct ActionData {
	InputAction action;
	ActionState state;
	float value;
};

class RS_InputActionListener {
public:
	int eventId = -1;
	virtual void HandleEvent(ActionData data) = 0;
	virtual void HandleEvent(ActionData data, int id) = 0;
};

class RS_Input {
public:
	static RS_Input& GetInstance()
	{
		static RS_Input instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}
	RS_Input(RS_Input const&) = delete;
	void operator=(RS_Input const&) = delete;

	void Update();
	bool IsKeyPressed(char key);

	void BindInputAction(RS_InputActionListener* listener, InputAction action);
	void UnbindInputAction(RS_InputActionListener* listener, InputAction action);
protected:

private:
	RS_Input() {
		log = &RS_Logger::GetInstance();

		for (int i = 0; i < 256; i++) {
			keys[i] = false;
		}
	};
	bool keys[256];
	SDL_Event inputEvent;
	RS_Logger* log;

	int eventNumber = 0;

	std::vector<RS_InputActionListener*> moveVListeners;
	std::vector<RS_InputActionListener*> moveHListeners;
	std::vector<RS_InputActionListener*> shootListeners;
	std::vector<RS_InputActionListener*> pauseListeners;
	std::vector<RS_InputActionListener*> exitListeners;
	std::vector<RS_InputActionListener*> fullSListeners;
	std::vector<RS_InputActionListener*> soundListeners;
	std::vector<RS_InputActionListener*> enterKeyListeners;

	void DispatchActionEvent(std::vector<RS_InputActionListener*> list, ActionData data);
	void UnbindInputAction(std::vector<RS_InputActionListener*> list, RS_InputActionListener* listener);
};

