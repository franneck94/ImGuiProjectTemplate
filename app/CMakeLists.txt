add_executable(${EXE_NAME}
        app/imgui_impl_glfw.h
        app/imgui_impl_glfw.cpp
        app/imgui_impl_opengl3.h
        app/imgui_impl_opengl3.cpp
        app/main.cpp)

target_link_libraries(${EXECUTABLE_NAME} PUBLIC
    ${LIBRARY_NAME}
    fmt::fmt
    spdlog::spdlog_header_only
    nlohmann_json
    ${CONAN_CXXOPTS}
)

if (${ENABLE_WARNINGS})
    target_set_warnings(TARGET ${LIBRARY_NAME} ENABLE ON AS_ERROR OFF)
endif()
