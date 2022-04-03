#pragma once

#include <filesystem>

#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h>

#include "render.hpp"

void start_cycle();

void end_cycle(GLFWwindow *const window);

void cycle_function(GLFWwindow *const window);
