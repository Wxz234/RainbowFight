#pragma once
#include <DirectXMath.h>
namespace RainbowFight {
	struct Camera {
		Camera() {
			position = DirectX::XMFLOAT3(0, 0, 0);
			target = DirectX::XMFLOAT3(0, 0, 1);
			up = DirectX::XMFLOAT3(0, 1, 0);
		}

		DirectX::XMFLOAT3 position;
		DirectX::XMFLOAT3 target;
		DirectX::XMFLOAT3 up;
	};
}