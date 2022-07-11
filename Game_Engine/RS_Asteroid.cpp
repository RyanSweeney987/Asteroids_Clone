#include "RS_Asteroid.h"
#include "RS_WindowController.h"

RS_Asteroid::RS_Asteroid(int x, int y, int width, int height, RS_Sprite& sprite) : RS_GameObject(x, y, width, height, sprite)
{
	// Set random initial vector and rotation
}

void RS_Asteroid::Update()
{
	transform.Move(movement);
	transform.Rotate(rotation);

	int screenWidth = RS_WindowController::GetInstance().GetWindowWidth();

	if (transform.position.x > screenWidth) {
		transform.position.x = 0;
	}
	if (transform.position.x < 0 - sprite.GetSize().w) {
		transform.position.x = screenWidth;
	}

	int screenHeight = RS_WindowController::GetInstance().GetWindowHeight();

	if (transform.position.y > screenHeight) {
		transform.position.y = 0;
	}
	if (transform.position.y < 0 - sprite.GetSize().h) {
		transform.position.y = screenHeight;
	}
}

void RS_Asteroid::HandleEvent(ActionData data)
{
}

void RS_Asteroid::HandleEvent(ActionData data, int id)
{
}

void RS_Asteroid::OnCollisionEnter()
{

}

void RS_Asteroid::OnCollisionExit()
{
}
