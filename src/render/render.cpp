#include "imgui.h"
#include "implot.h"

#include "render.hpp"

void render()
{
    ImGui::NewFrame();

    ImGui::Button("TEST");

    ImGui::Render();
}
