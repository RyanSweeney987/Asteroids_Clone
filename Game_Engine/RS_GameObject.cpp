#include "RS_GameObject.h"
#include <iostream>


//RS_GameObject::RS_GameObject()
//{
//}

RS_GameObject::RS_GameObject(int x, int y, int width, int height, RS_Sprite& sprite): sprite(sprite), collider(this)
{
	transform.position.x = x;
	transform.position.y = y;

	input = &RS_Input::GetInstance();
	log = &RS_Logger::GetInstance();


}

RS_GameObject::~RS_GameObject()
{
	//delete &sprite;
}

//void RS_GameObject::Init(int x, int y, int w, int h)
//{
//	transform.position.x = x;
//	transform.position.y = y;
//}

//void RS_GameObject::Update()
//{
//
//}
//
//void RS_GameObject::Input()
//{
//
//}

//void RS_GameObject::Render(SDL_Renderer* renderer)
//{
//	//if(sprite != NULL)
//		SDL_RenderCopy(renderer, texture, NULL, bounds);
//}

//RS_Sprite& RS_GameObject::GetSprite()
//{
//	return *sprite;
//}

RS_Transform& RS_GameObject::GetTransform()
{
	return transform;
}

RS_Sprite& RS_GameObject::GetSprite()
{
	return sprite;
}

RS_Collider& RS_GameObject::GetCollider()
{
	return collider;
}

//void RS_GameObject::SetSprite(RS_Sprite* sprite)
//{
//	this->sprite = sprite;
//}

void RS_GameObject::SetTransform(RS_Transform newTransform)
{
	transform = newTransform;
}

void RS_GameObject::SetCollider(RS_Collider& collider)
{
	this->collider = collider;
}

void RS_GameObject::OnCollisionEnter()
{
}

void RS_GameObject::OnCollisionExit()
{
}
