#include "RS_Sprite.h"
#include "RS_Logger.h"

RS_Sprite::RS_Sprite(RS_Texture& texture) : RS_Sprite(texture, 0, 0, 1, 1)
{
}

RS_Sprite::RS_Sprite(RS_Texture& texture, unsigned int indexX = 0, unsigned int indexY = 0, unsigned int gridX = 1, unsigned int gridY = 1) : indexX(indexX), indexY(indexY), gridX(gridX), gridY(gridY), texture(texture)
{
	if (gridX == 0) {
		gridX = 1;
	}
	if (gridY == 0) {
		gridY = 1;
	}

	int spriteWidth = texture.GetWidth() / gridX;
	int spriteHeight = texture.GetHeight() / gridY;

	int x = spriteWidth * indexX;
	int y = spriteHeight * indexY;

	size.x = x;
	size.y = y;
	size.w = spriteWidth;
	size.h = spriteHeight;

	RS_Logger::GetInstance().Log("Texture width: " + std::to_string(texture.GetWidth()) + ", height: " + std::to_string(texture.GetHeight()));
	
	bounds = new SDL_Rect();

	bounds->x = indexX * spriteWidth;
	bounds->h = indexY * spriteHeight;
	bounds->w = spriteWidth;
	bounds->h = spriteHeight;
}

bool RS_Sprite::IsRenderEnabled()
{
	return renderEnabled;
}

unsigned int RS_Sprite::GetCurrentSequence()
{
	return currentSequence;
}

SDL_Rect& RS_Sprite::GetSpriteBounds()
{
	return *bounds;
}

SDL_Rect& RS_Sprite::GetSize()
{
	return size;
}

RS_Texture& RS_Sprite::GetTexture()
{
	return texture;
}

void RS_Sprite::SetRenderEnabled(bool renderEnabled)
{
	this->renderEnabled = renderEnabled;
}

void RS_Sprite::SetAnimationSequence(unsigned int sequence)
{
	Stop();
	currentSequence = sequence;
}

RS_Sprite::RS_Sprite(RS_Texture& texture, unsigned int gridX = 1, unsigned int gridY = 1) : RS_Sprite(texture, 0, 0, gridX, gridY)
{
	timer->AddCallbackFunction(this);
}

RS_Sprite::~RS_Sprite()
{
	delete bounds;
	delete timer;

	for (auto&& sequence : animationStates) {
		delete sequence;
	}
}

void RS_Sprite::Play(unsigned int sequence)
{
	if (animationStates.size() > 0) {
		currentSequence = sequence;
		timer->StartTimer();
	}
}

void RS_Sprite::Stop()
{
	if (animationStates.size() > 0) {
		timer->StopTimer();
	}
}

void RS_Sprite::Update()
{
	if (animationStates.size() > 0) {
		timer->Update();
	}
}

void RS_Sprite::AddAnimationSequence(RS_AnimationSequence* sequence)
{
	animationStates.push_back(sequence);
}

void RS_Sprite::Run()
{
	RS_AnimationFrame frame = animationStates[currentSequence]->GetCurrentFrame();
	int xPos = frame.indexX;
	int yPos = frame.indexY;

	int spriteWidth = texture.GetWidth() / gridX;
	int spriteHeight = texture.GetHeight() / gridY;

	int x = spriteWidth * xPos;
	int y = spriteHeight * yPos;

	bounds->x = spriteWidth * xPos;
	bounds->y = spriteHeight * yPos;
}

RS_AnimationSequence::~RS_AnimationSequence()
{
	for (auto&& frame : frames) {
		delete frame;
	}
}

RS_AnimationFrame& RS_AnimationSequence::GetCurrentFrame()
{
	int frame = currentFrame;
	currentFrame += 1;

	if (loopCount > 0) { // We loop
		currentLoop += 1;

		if (currentLoop < loopCount) {
			if (currentFrame == frames.size()) {
				currentFrame = 0;
			}
		}
	}
	else if (loopCount < 0) { // We loop infinitely
		if (currentFrame == frames.size()) {
			currentFrame = 0;
		}
	}
	else { // We play once
		if (currentFrame == frames.size()) {
			currentFrame = frame;
		}
	}

	return *frames[frame];
}

void RS_AnimationSequence::SetLoopCount(int loopCount)
{
	this->loopCount = loopCount;
}

void RS_AnimationSequence::SetBounce(bool bounce)
{
	this->bounce = bounce;
}

void RS_AnimationSequence::AddAnimationFrames(RS_AnimationFrame& frame)
{
	frames.push_back(&frame);
}
