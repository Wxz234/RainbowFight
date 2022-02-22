#include "Device.h"
#include <d3d11_4.h>
#include <dxgi1_6.h>
#include <d3dcommon.h>
#include <wrl/client.h>
namespace RainbowFight {
	struct Device::Impl {
		Microsoft::WRL::ComPtr<ID3D11Device> m_Device;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_DeviceContext;
		Microsoft::WRL::ComPtr<IDXGISwapChain1> m_swapChain;
	};

	Device::Device(HWND hwnd, uint32_t w, uint32_t h) {
		_pimpl = new Impl;
		UINT createDeviceFlags = 0;
#if defined(DEBUG) || defined(_DEBUG)  
        createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
        D3D_FEATURE_LEVEL featureLevels[] =
        {
            D3D_FEATURE_LEVEL_11_1,
            D3D_FEATURE_LEVEL_11_0,
        };
        D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, featureLevels, 2, D3D11_SDK_VERSION, _pimpl->m_Device.GetAddressOf(), nullptr, _pimpl->m_DeviceContext.GetAddressOf());
		Microsoft::WRL::ComPtr<IDXGIDevice> pDXGIDevice;
		auto g_pd3dDevice = _pimpl->m_Device.Get();
		g_pd3dDevice->QueryInterface(IID_PPV_ARGS(&pDXGIDevice));

		Microsoft::WRL::ComPtr<IDXGIAdapter> pDXGIAdapter;
		pDXGIDevice->GetAdapter(&pDXGIAdapter);

		Microsoft::WRL::ComPtr<IDXGIFactory7> pIDXGIFactory;
		pDXGIAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&pIDXGIFactory);

		DXGI_SWAP_CHAIN_DESC1 _desc = {};
		_desc.BufferCount = 1;
		_desc.Width = w;
		_desc.Height = h;
		_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		_desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		_desc.SampleDesc.Count = 1;
		_desc.SampleDesc.Quality = 0;
		_desc.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
		_desc.Scaling = DXGI_SCALING_STRETCH;

		DXGI_SWAP_CHAIN_FULLSCREEN_DESC fsSwapChainDesc = {};
		fsSwapChainDesc.Windowed = TRUE;
		
		pIDXGIFactory->CreateSwapChainForHwnd(g_pd3dDevice, hwnd, &_desc, &fsSwapChainDesc, nullptr, &_pimpl->m_swapChain);
		pIDXGIFactory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_WINDOW_CHANGES | DXGI_MWA_NO_ALT_ENTER);
	}
	Device::~Device() {
		delete _pimpl;
	}

	void Device::Present(bool isVSync) {
		if (isVSync) {
			_pimpl->m_swapChain->Present(1, 0);
		}
		else {
			_pimpl->m_swapChain->Present(0, 0);
		}
	}

	ID3D11Device* Device::GetDevice() const {
		return _pimpl->m_Device.Get();
	}
	ID3D11DeviceContext* Device::GetContext() const {
		return _pimpl->m_DeviceContext.Get();
	}
}
