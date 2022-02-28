#pragma once
#include <Windows.h>
namespace RainbowFight {
	void RegisterInputDevices(HWND hwnd);
	void UpdateInputMessage(HWND hwnd, LPARAM lParam);
	void ProcessInput();
	int GetDeltaX();
	int GetDeltaY();
}