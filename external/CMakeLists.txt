### IMGUI
set(IMGUI_SOURCES
    "imgui/imgui.cpp"
    "imgui/imgui_draw.cpp"
    "imgui/imgui_tables.cpp"
    "imgui/imgui_widgets.cpp")
add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC "imgui")

### GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("glfw")
target_link_libraries(glfw PUBLIC imgui)

### IMPLOT
set(IMPLOT_SOURCES
    "implot/implot_items.cpp"
    "implot/implot.cpp")
add_library(implot STATIC ${IMPLOT_SOURCES})
target_include_directories(implot PUBLIC "implot")
target_link_libraries(implot PUBLIC imgui)

### ALL GRAPHICAL LIBS
set(IMPL_SOURCES
    "imgui/backends/imgui_impl_glfw.h"
    "imgui/backends/imgui_impl_glfw.cpp"
    "imgui/backends/imgui_impl_opengl3.h"
    "imgui/backends/imgui_impl_opengl3.cpp")
add_library(impl STATIC ${IMPL_SOURCES})
target_include_directories(impl PUBLIC "imgui/backends/")
target_link_libraries(impl PUBLIC
    imgui
    implot
    glfw)

if(${ENABLE_LTO})
    target_enable_lto(impl optimized)
endif()
