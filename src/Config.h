#pragma once
#include <Windows.h>
#include <cstdint>
namespace RainbowFight {
	struct Config {
		uint32_t width = 800;
		uint32_t height = 600;
		bool isFullScreen = true;
		bool isVSync = true;
		bool isCursorLocked = false;
	};
}