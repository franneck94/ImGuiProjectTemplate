#include <iostream>

#include "imgui.h"
#include "implot.h"

#include "render.hpp"

void render()
{
    if (ImGui::Begin("Main"))
    {
        ImGui::Text("Hello World!");
        ImGui::End();
    }
}
