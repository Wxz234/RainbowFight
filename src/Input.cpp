#include "Input.h"
namespace RainbowFight {

	int lastX = 0;
	int thisX = 0;
	int deltaX = 0;
	int lastY = 0;
	int thisY = 0;
	int deltaY = 0;
	bool leftclick = false;
	bool rightclick = false;

	void RegisterInputDevices(HWND hwnd) {
		RAWINPUTDEVICE Rid[2] = {};

		Rid[0].usUsagePage = 0x01;          // HID_USAGE_PAGE_GENERIC
		Rid[0].usUsage = 0x02;              // HID_USAGE_GENERIC_MOUSE
		Rid[0].dwFlags = 0;					// RIDEV_NOLEGACY
		Rid[0].hwndTarget = 0;

		Rid[1].usUsagePage = 0x01;          // HID_USAGE_PAGE_GENERIC
		Rid[1].usUsage = 0x06;              // HID_USAGE_GENERIC_KEYBOARD
		Rid[1].dwFlags = 0;
		Rid[1].hwndTarget = 0;

		RegisterRawInputDevices(Rid, 2, sizeof(Rid[0]));
	}

	void UpdateInputMessage(HWND hwnd,LPARAM lParam,const Config &config) {
		UINT dwSize = 0;
		GetRawInputData((HRAWINPUT)lParam, RID_INPUT, NULL, &dwSize, sizeof(RAWINPUTHEADER));
		LPBYTE lpb = new BYTE[dwSize];
		GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

		RAWINPUT* raw = (RAWINPUT*)lpb;
		if (raw->header.dwType == RIM_TYPEKEYBOARD) {
			
		}
		else if (raw->header.dwType == RIM_TYPEMOUSE) {
			thisX += raw->data.mouse.lLastX;
			thisY += raw->data.mouse.lLastY;

			if (thisX >= 10000000) {
				thisX -= 10000000;
				lastX -= 10000000;
			}else if (thisX <= -10000000) {
				thisX += 10000000;
				lastX += 10000000;
			}
			if (thisY >= 10000000) {
				thisY -= 10000000;
				lastY -= 10000000;
			}
			else if (thisY <= -10000000) {
				thisY += 10000000;
				lastY += 10000000;
			}

			if (raw->data.mouse.usButtonFlags & RI_MOUSE_LEFT_BUTTON_DOWN) {
				leftclick = true;
			}
			else if(raw->data.mouse.usButtonFlags & RI_MOUSE_LEFT_BUTTON_UP) {
				leftclick = false;
			}

			if (raw->data.mouse.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_DOWN) {
				rightclick = true;
			}
			else if (raw->data.mouse.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_UP) {
				rightclick = false;
			}

			if (config.isCursorLocked) {
				POINT point = { config.width / 2,config.height / 2 };
				ClientToScreen(hwnd, &point);
				SetCursorPos(point.x, point.y);
			}
		}

		delete[] lpb;
	}


	void ProcessInput() {
		deltaX = thisX - lastX;
		deltaY = thisY - lastY;
		lastX = thisX;
		lastY = thisY;
	}

	int GetDeltaX() {
		return deltaX;
	}
	int GetDeltaY() {
		return deltaY;
	}
}