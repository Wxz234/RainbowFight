add_executable(RainbowFight WIN32 
	main.cpp
	Camera.cpp
	Shader.cpp
	Device.cpp
)
target_compile_definitions(RainbowFight PRIVATE UNICODE)
target_link_libraries(RainbowFight PRIVATE d3d11 dxguid dxgi d3dcompiler)
target_compile_definitions(RainbowFight PRIVATE RAINBOWFIGHT_PATH="${PROJECT_SOURCE_DIR}")