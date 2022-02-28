#include <Windows.h>
#include "Camera.h"
#include "Shader.h"
#include "Device.h"
#include "Config.h"
#include "Light.h"
#include "Model.h"
#include "Input.h"
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        break;

    case WM_INPUT:
    {
        RainbowFight::UpdateInputMessage(hWnd, lParam);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}



int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    RainbowFight::Config config;
    WNDCLASSEXW wcex = {};
    wcex.cbSize = sizeof(WNDCLASSEXW);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = GetModuleHandle(nullptr);
    wcex.hIcon = LoadIconW(wcex.hInstance, L"IDI_ICON");
    wcex.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    wcex.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
    wcex.lpszClassName = L"RainbowFight";
    wcex.hIconSm = LoadIconW(wcex.hInstance, L"IDI_ICON");
    RegisterClassExW(&wcex);

    RECT rc = { 0, 0, static_cast<LONG>(config.width), static_cast<LONG>(config.height) };
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX, FALSE);
    HWND hwnd = CreateWindowExW(0, L"RainbowFight", L"RainbowFight", WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, GetModuleHandle(nullptr), nullptr);
    
    RainbowFight::Device device(hwnd, config.width, config.height);

    RainbowFight::RegisterInputDevices(hwnd);

    ShowWindow(hwnd, SW_SHOWDEFAULT);
    MSG msg = {};
    while (WM_QUIT != msg.message) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            //input 
            RainbowFight::ProcessInput();
            RainbowFight::SetCursorPos();
            device.Present(config.isVSync);
        }
    }

    return 0;
}
