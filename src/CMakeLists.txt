#imgui
add_library(imgui STATIC 
	${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui.cpp
	${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui_demo.cpp
	${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui_draw.cpp
	${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui_tables.cpp
	${PROJECT_SOURCE_DIR}/thirdparty/imgui/imgui_widgets.cpp
	${PROJECT_SOURCE_DIR}/thirdparty/imgui/backends/imgui_impl_win32.cpp
	${PROJECT_SOURCE_DIR}/thirdparty/imgui/backends/imgui_impl_dx11.cpp
)
target_include_directories(imgui PUBLIC ${PROJECT_SOURCE_DIR}/thirdparty/imgui ${PROJECT_SOURCE_DIR}/thirdparty/imgui/backends)

add_executable(RainbowFight WIN32 
	"main.cpp"
	"Camera.cpp"
	"Shader.cpp"
	"Device.cpp"
	"Light.cpp"
	"Model.cpp"
	"Input.cpp"
	"Config.cpp"
	"DDSTextureLoader11.cpp"
)
target_compile_definitions(RainbowFight PRIVATE UNICODE)
target_link_libraries(RainbowFight PRIVATE d3d11 dxguid dxgi d3dcompiler imgui)
set_target_properties(RainbowFight PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
add_custom_command(TARGET RainbowFight PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:RainbowFight>/shaders)