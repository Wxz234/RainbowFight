#include "Shader.h"
#include <d3dcompiler.h>
#include <string>
namespace RainbowFight {
	std::wstring getPath(const wchar_t* path) {
		return std::wstring(RAINBOWFIGHT_PATH) + path;
	}

	ShaderBlob CompileSkyBoxShader() {
		auto vs_path = getPath(L"/shaders/skybox_vs.hlsl");
		
		return ShaderBlob();
	}
}

