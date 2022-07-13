#pragma once
#include <SDL.h>
#include <functional>
#include "RS_Transform.h"
#include "RS_Sprite.h"
#include "RS_Input.h"
#include "RS_Logger.h"
#include "RS_Collider.h"

class RS_GameObject: public RS_InputActionListener, public RS_CollisionListener {
public:
	RS_GameObject(int x, int y, int width, int height, RS_Sprite& sprite);
	~RS_GameObject();

	//RS_Sprite& GetSprite();
	RS_Transform& GetTransform();
	RS_Sprite& GetSprite();
	RS_Collider& GetCollider();

	//void SetSprite(RS_Sprite* sprite);
	void SetTransform(RS_Transform transform);
	void SetCollider(RS_Collider& collider);

	//virtual void Init(int x, int y, int w, int h);
	virtual void Update() = 0;
	//std::function<void()> Input = []() -> void {};
	//virtual void Input() = 0;
	//virtual void Render(SDL_Renderer* renderer);
	//virtual void Destroy();

protected:
	//bool isCollider;
	bool isTrigger;

	RS_Transform transform;
	RS_Sprite sprite;
	RS_Collider collider;
	RS_Input* input;
	RS_Logger* log;

	virtual void HandleEvent(ActionData data) override = 0;
	virtual void HandleEvent(ActionData data, int id) override = 0;

	// Inherited via RS_CollisionListener
	virtual void OnCollisionEnter() override = 0;
	virtual void OnCollisionExit() override = 0;
};