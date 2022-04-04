#include "imgui.h"
#include "implot.h"

#include "render.hpp"

void render()
{
    ImGui::NewFrame();

    int i = 1;
    ImGui::Button("TEST");

    ImGui::Render();
}
