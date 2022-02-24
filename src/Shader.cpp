#include "Shader.h"
#include <d3dcompiler.h>
#include <string>
namespace RainbowFight {
	std::wstring GetShaderPath(const wchar_t* path) {
		return std::wstring(RAINBOWFIGHT_PATH) + path;
	}

	ShaderBlob CompileSkyBoxShader() {
		ShaderBlob blob;
		auto vs_path = GetShaderPath(L"/shaders/skybox_vs.hlsl");
		auto ps_path = GetShaderPath(L"/shaders/skybox_ps.hlsl");
		D3DCompileFromFile(vs_path.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "vs_5_0", 0, 0, &blob.vs, nullptr);
		D3DCompileFromFile(ps_path.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", 0, 0, &blob.ps, nullptr);

		return blob;
	}
}

