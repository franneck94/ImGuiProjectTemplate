add_library(imgui
    "imgui/imgui.cpp"
    "imgui/imgui_draw.cpp"
    "imgui/imgui_demo.cpp"
    "imgui/imgui_tables.cpp"
    "imgui/imgui_widgets.cpp")
target_include_directories(imgui PUBLIC "imgui")
target_set_warnings(TARGET imgui ENABLE OFF AS_ERROR OFF)

set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("glfw")
target_link_libraries(glfw PUBLIC imgui)
target_set_warnings(TARGET glfw ENABLE OFF AS_ERROR OFF)

add_library(implot
    "implot/implot_demo.cpp"
    "implot/implot_items.cpp"
    "implot/implot.cpp")
target_include_directories(implot PUBLIC "implot")
target_link_libraries(implot PUBLIC imgui)
target_set_warnings(TARGET implot ENABLE OFF AS_ERROR OFF)

add_library(impl
    "impl/imgui_impl_glfw.h"
    "impl/imgui_impl_glfw.cpp"
    "impl/imgui_impl_opengl3.h"
    "impl/imgui_impl_opengl3.cpp")
target_include_directories(impl PUBLIC "impl")
target_link_libraries(impl PUBLIC
    imgui
    implot
    glfw)
target_set_warnings(TARGET impl ENABLE OFF AS_ERROR OFF)
