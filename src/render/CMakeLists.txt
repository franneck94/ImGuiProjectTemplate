set(LIBRARY_SOURCES "render.cpp")
set(LIBRARY_HEADERS "render.hpp")
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library("render" STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories("render" PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries("render" PRIVATE fmt::fmt-header-only)
target_link_libraries("render" PRIVATE glfw)
target_link_libraries("render" PRIVATE OpenGL::GL)
target_link_libraries("render" PRIVATE imgui::imgui)
target_link_libraries("render" PRIVATE implot::implot)

target_set_warnings(
    TARGET
    "render"
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})

if(${ENABLE_LTO})
    target_enable_lto("render" optimized)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_clang_tidy_to_target("render")
endif()
