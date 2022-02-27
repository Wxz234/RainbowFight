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



	void RegisterInputDevices(HWND hwnd){
		RAWINPUTDEVICE Rid[2] = {};

		Rid[0].usUsagePage = 0x01;          // HID_USAGE_PAGE_GENERIC
		Rid[0].usUsage = 0x02;              // HID_USAGE_GENERIC_MOUSE
		Rid[0].dwFlags = 0;   
		Rid[0].hwndTarget = hwnd;

		Rid[1].usUsagePage = 0x01;          // HID_USAGE_PAGE_GENERIC
		Rid[1].usUsage = 0x06;              // HID_USAGE_GENERIC_KEYBOARD
		Rid[1].dwFlags = 0;   
		Rid[1].hwndTarget = hwnd;

		RegisterRawInputDevices(Rid, 2, sizeof(Rid[0]));
	}

	void UpdateInputMessage(HWND hwnd,LPARAM lParam) {
		UINT dwSize = 0;
		GetRawInputData((HRAWINPUT)lParam, RID_INPUT, NULL, &dwSize, sizeof(RAWINPUTHEADER));
		LPBYTE lpb = new BYTE[dwSize];
		if (GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER)) != dwSize)
			OutputDebugString(TEXT("GetRawInputData does not return correct size !\n"));

		RAWINPUT* raw = (RAWINPUT*)lpb;
		if (raw->header.dwType == RIM_TYPEKEYBOARD) {
			
		}
		else if (raw->header.dwType == RIM_TYPEMOUSE) {
			thisX += raw->data.mouse.lLastX;
			thisY += raw->data.mouse.lLastY;

			if (raw->data.mouse.usButtonFlags & RI_MOUSE_LEFT_BUTTON_DOWN) {
				//inputmessage.leftclick = true;
			}
			else if(raw->data.mouse.usButtonFlags & RI_MOUSE_LEFT_BUTTON_UP) {
				//inputmessage.leftclick = false;

			}

			if (raw->data.mouse.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_DOWN) {
				//inputmessage.leftclick = true;
			}
			else if (raw->data.mouse.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_UP) {
				//inputmessage.leftclick = false;
			}
		}

		delete[] lpb;
	}


	void processInput() {
		deltaX = thisX - lastX;
		deltaY = thisY - lastY;
	}

}