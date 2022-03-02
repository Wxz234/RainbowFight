#include "Debug.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
namespace RainbowFight {

    static ID3D11DeviceContext* mainContext = nullptr;
	void ImguiInit(Device* pDevice) {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGui_ImplWin32_Init(pDevice->GetHWND());
        ImGui_ImplDX11_Init(pDevice->GetDevice(), pDevice->GetContext());
        mainContext = pDevice->GetContext();
	}

    void ImguiRelease() {
        ImGui_ImplDX11_Shutdown();
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();
    }

    LRESULT ImguiWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        return ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam);
    }

    void ImguiNewFrame() {
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
    }
    void ImguiRender(ID3D11RenderTargetView *rtv) {
        ImGui::Render();
        mainContext->OMSetRenderTargets(1, &rtv, NULL);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    }
}