#pragma once
#include <Windows.h>
#include <d3d11_4.h>
#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>
#include "Device.h"
namespace RainbowFight {
	void ImguiInit(Device* pDevice);
	void ImguiRelease();
	LRESULT ImguiWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void ImguiNewFrame();
	void ImguiRender(ID3D11RenderTargetView* rtv);
}