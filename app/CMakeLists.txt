set(EXE_SOURCES "main.cpp" "cycle.cpp")
set(EXE_HEADERS "cycle.hpp")
add_executable("main" ${EXE_SOURCES} ${EXE_HEADERS})
target_link_libraries("main" PRIVATE fmt::fmt-header-only)
target_link_libraries("main" PRIVATE glfw)
target_link_libraries("main" PRIVATE OpenGL::GL)
target_link_libraries("main" PRIVATE imgui::imgui)
target_link_libraries("main" PRIVATE implot::implot)
target_link_libraries("main" PRIVATE render)

target_set_warnings(
    TARGET
    "main"
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})

if(${ENABLE_LTO})
    target_enable_lto("main" optimized)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_clang_tidy_to_target("main")
endif()
