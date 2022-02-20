#pragma once
#include <Windows.h>
#include <cstdint>
namespace RainbowFight {
    struct Device {
        Device(HWND hwnd,uint32_t w, uint32_t h);
        ~Device();
        void Present();
    private:
        struct Impl;
        Impl *_pimpl;
    };

}