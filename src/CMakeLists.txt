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
set_target_properties(RainbowFight PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})