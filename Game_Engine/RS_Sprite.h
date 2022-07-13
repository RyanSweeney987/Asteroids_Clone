#pragma once
#include <SDL.h>
#include "RS_Texture.h"
#include <vector>
#include "RS_Timer.h"

// TODO Inlcude animated sprites

	//unsigned int calcX = (frameWidthPixel * frameIndex);
	//SDL_Rect src = { calcX, 0 , frameWidthPixels, frameHeightPixels };

	//SDL_Rect dest = { x, y, frameWidthPixels, frameHeightPixels };
	//SDL_RenderCopy(renderer, texture, &src, &dest);
	//SDL_RenderCopyEx Renders and rotates by angle
	// Scale by modifying the dest rectangle

	// Array of rects
	// Each one is frameWidth * frameIndex
	// Change every 200ms

struct RS_AnimationFrame {
public:
	RS_AnimationFrame(unsigned int indexX, unsigned int indexY) : indexX(indexX), indexY(indexY) {};
	unsigned int indexX;
	unsigned int indexY;
};

struct RS_AnimationSequence {
public:
	~RS_AnimationSequence();

	RS_AnimationFrame& GetCurrentFrame();

	void SetLoopCount(int loopCount);
	void SetBounce(bool bounce);
	void AddAnimationFrames(RS_AnimationFrame& frame);
private:
	unsigned int currentFrame = 0;
	int loopCount = 0;
	unsigned int currentLoop = 0;
	bool bounce = false;
	bool forward = false;
	std::vector<RS_AnimationFrame*> frames;
};

class RS_Sprite: public RS_TimerCallback {
public:
	RS_Sprite(RS_Texture& texture);
	RS_Sprite(RS_Texture& texture, unsigned int gridX, unsigned int gridY);
	RS_Sprite(RS_Texture& texture, unsigned int indexX, unsigned int indexY, unsigned int gridX, unsigned int gridY);
	~RS_Sprite();

	bool IsRenderEnabled();
	unsigned int GetCurrentSequence();
	SDL_Rect& GetSpriteBounds();
	SDL_Rect& GetSize();
	RS_Texture& GetTexture();

	void SetRenderEnabled(bool renderEnabled);
	void SetAnimationSequence(unsigned int sequence);

	void AddAnimationSequence(RS_AnimationSequence* sequence);

	void Play(unsigned int sequence);
	void Stop();
	void Update();
private:
	const float FRAME_RATE = 1000.0f / 2.0f; // Two frames per second
	unsigned int currentSequence = 0;
	unsigned int gridX = 1;
	unsigned int gridY = 1;
	unsigned int indexX = 0;
	unsigned int indexY = 0;
	bool renderEnabled = true;

	SDL_Rect size;		// Display bounds			- dst
	SDL_Rect* bounds;	// Internal texture bounds	- src
	RS_Texture texture;
	RS_Timer* timer = new RS_Timer(FRAME_RATE, true);
	std::vector<RS_AnimationSequence*> animationStates;

	virtual void Run() override;
};

//class RS_AnimatedSprite : public RS_Sprite, public RS_TimerCallback {
//public:
//	RS_AnimatedSprite(RS_Texture& texture, unsigned int gridX, unsigned int gridY);
//	~RS_AnimatedSprite();
//
//	void Play(unsigned int sequence);
//	void Stop();
//	void Update();
//
//	void AddAnimationSequence(RS_AnimationSequence* sequence);
//private:
//	const float FRAME_RATE = 1000.0f / 2.0f; // Two frames per second
//	int currentSequence = 0;
//
//	RS_Timer timer = RS_Timer(FRAME_RATE, true);
//	std::vector<RS_AnimationSequence*> animationStates;
//
//	// Inherited via RS_TimerCallback
//	virtual void Run() override;
//};

