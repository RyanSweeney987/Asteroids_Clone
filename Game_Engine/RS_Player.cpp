#include "RS_Player.h"
#include "RS_Input.h"
#include "RS_WindowController.h"

RS_Player::RS_Player(int x, int y, int width, int height, RS_Sprite& sprite): RS_GameObject(x, y, width, height, sprite)
{

}

RS_Player::~RS_Player()
{
	
}

void RS_Player::Update()
{
	sprite.Update();

	if (input->IsKeyPressed('w')) {
		log->Log("Player: Pressing W");
		transform.MoveForward(1);

		if (sprite.GetCurrentSequence() != 1) {
			sprite.SetAnimationSequence(1);
		}
	}
	if (input->IsKeyPressed('s')) {
		log->Log("Player: Pressing S");
		transform.MoveForward(-1);

		if (sprite.GetCurrentSequence() != 1) {
			sprite.SetAnimationSequence(1);
		}
	}
	if (input->IsKeyPressed('a')) {
		log->Log("Player: Pressing A");
		transform.Rotate(-2);

		if (sprite.GetCurrentSequence() != 1) {
			sprite.SetAnimationSequence(1);
		}
	}
	if (input->IsKeyPressed('d')) {
		log->Log("Player: Pressing D");
		transform.Rotate(2);

		if (sprite.GetCurrentSequence() != 1) {
			sprite.SetAnimationSequence(1);
		}
	}

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

void RS_Player::HandleEvent(ActionData data)
{
}

void RS_Player::HandleEvent(ActionData data, int id)
{
}

void RS_Player::OnCollisionEnter()
{
	log->Log("Player: collision enter");
	health -= 100;
}

void RS_Player::OnCollisionExit()
{
	log->Log("Player: collision exit");
}
