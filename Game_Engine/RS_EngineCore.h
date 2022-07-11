#pragma once

#include "SDL.h"
<<<<<<< Updated upstream
#include "RS_Time.h"
#include "RS_GameWorld.h"
=======
#include "SDL_image.h"
#include "RS_Time.h"
#include "RS_GameWorld.h"
#include "RS_TextureManager.h"
#include "RS_SoundManager.h"

// Some random TheCherno code to log memory usage
//struct AllocationMetrics {
//	uint32_t TotalAllocated = 0;
//	uint32_t TotalFreed = 0;
//
//	uint32_t CurrentUsage() {
//		return TotalAllocated - TotalFreed;
//	}
//
//	void PrintMemoryUsage() {
//		std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes" << std::endl;
//	}
//};
//
//static AllocationMetrics s_AllocationMetrics;
//
//void* operator new(size_t size) {
//	s_AllocationMetrics.TotalAllocated += size;
//
//	return malloc(size);
//}
//
//void operator delete(void* memory, size_t size) {
//	s_AllocationMetrics.TotalFreed += size;
//
//	free(memory);
//}
>>>>>>> Stashed changes

class RS_EngineCore {
public:
	RS_EngineCore();
	~RS_EngineCore();
<<<<<<< Updated upstream
	int start();
private:
	int run();
	int stop();
	RS_GameWorld mainWorld;
=======

	void Start();
private:
	RS_Logger* log;

	void Run();
>>>>>>> Stashed changes
};