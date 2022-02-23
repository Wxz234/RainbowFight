add_executable(RainbowFight WIN32 
	main.cpp
	Camera.cpp
	Shader.cpp
	Device.cpp
	Light.cpp
	DDSTextureLoader11.cpp
)
target_compile_definitions(RainbowFight PRIVATE UNICODE)
target_link_libraries(RainbowFight PRIVATE d3d11 dxguid dxgi d3dcompiler)
target_compile_definitions(RainbowFight PRIVATE RAINBOWFIGHT_PATH=L"${PROJECT_SOURCE_DIR}")