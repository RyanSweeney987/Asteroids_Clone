#include "RS_Background.h"

RS_Background::RS_Background(RS_Sprite& background) : RS_GameObject(0, 0, 1280, 720, background)
{
	collider.SetIsEnabled(false);
}

void RS_Background::Update()
{
}

void RS_Background::HandleEvent(ActionData data)
{
}

void RS_Background::HandleEvent(ActionData data, int id)
{
}

void RS_Background::OnCollisionEnter()
{
}

void RS_Background::OnCollisionExit()
{
}
