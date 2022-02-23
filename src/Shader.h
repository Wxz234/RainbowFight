#pragma once
#include <d3dcommon.h>
#include <wrl/client.h>
namespace RainbowFight {
	struct ShaderBlob {
		Microsoft::WRL::ComPtr<ID3DBlob> vs;
		Microsoft::WRL::ComPtr<ID3DBlob> ps;
	};

	ShaderBlob CompileSkyBoxShader();
}