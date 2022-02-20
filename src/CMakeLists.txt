add_executable(RainbowFight WIN32 
	main.cpp
	Camera.cpp
	Shader.cpp
)

target_compile_definitions(RainbowFight PRIVATE RAINBOWFIGHT_PATH="${PROJECT_SOURCE_DIR}")