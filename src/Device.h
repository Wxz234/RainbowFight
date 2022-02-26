#pragma once
#include <Windows.h>
#include <d3d11_4.h>
#include <cstdint>
namespace RainbowFight {
    struct Device {
        Device(HWND hwnd,uint32_t w, uint32_t h);
        ~Device();
        void Present(bool isVSync);
        ID3D11Device* GetDevice() const;
        ID3D11DeviceContext* GetContext() const;
        void CreateDeferredContext(ID3D11DeviceContext** ppDeferredContext);
    private:
        struct Impl;
        Impl *_pimpl;
    };

}