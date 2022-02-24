#include "Shader.h"
#include <d3dcompiler.h>
namespace RainbowFight {

	ShaderBlob CompileSkyBoxShader() {
		ShaderBlob blob;
		D3DCompileFromFile(L"shaders/skybox_vs.hlsl", nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "vs_5_0", 0, 0, &blob.vs, nullptr);
		D3DCompileFromFile(L"shaders/skybox_ps.hlsl", nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", 0, 0, &blob.ps, nullptr);

		return blob;
	}
}

