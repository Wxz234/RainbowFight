#pragma once
#include <Windows.h>
#include "Config.h"
namespace RainbowFight {
	void RegisterInputDevices(HWND hwnd);
	void UpdateInputMessage(HWND hwnd, LPARAM lParam, const Config& config);
	void ProcessInput();
	int GetDeltaX();
	int GetDeltaY();
}