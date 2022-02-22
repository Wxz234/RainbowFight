#pragma once
#include <Windows.h>
#include <cstdint>
namespace RainbowFight {
	struct Config {
		uint32_t width = 1024;
		uint32_t height = 768;
		bool isFullScreen = false;
		bool isVSync = true;
	};
}