#include <iostream>

#include "imgui.h"
#include "implot.h"

#include "render.hpp"

void ShowDemo_LinePlots() {
    static float xs1[1001], ys1[1001];
    for (int i = 0; i < 1001; ++i) {
        xs1[i] = i * 0.001f;
        ys1[i] = 0.5f + 0.5f * sinf(50 * (xs1[i] + (float)ImGui::GetTime() / 10));
    }
    static double xs2[11], ys2[11];
    for (int i = 0; i < 11; ++i) {
        xs2[i] = i * 0.1f;
        ys2[i] = xs2[i] * xs2[i];
    }
    ImGui::BulletText("Anti-aliasing can be enabled from the plot's context menu (see Help).");
    if (ImPlot::BeginPlot("Line Plot")) {
        ImPlot::SetupAxes("x","f(x)");
        ImPlot::PlotLine("sin(x)", xs1, ys1, 1001);
        ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
        ImPlot::PlotLine("x^2", xs2, ys2, 11);
        ImPlot::EndPlot();
    }
}

void render()
{
    ImGui::NewFrame();

    ImGui::SetNextWindowPos(ImVec2{0.0, 0.0});
    ImGui::SetNextWindowSize(ImVec2{300.0, 150.0});

    if (ImGui::Begin("window1"))
    {
        if (ImGui::BeginTable("table1", 3, ImGuiTableFlags_Borders))
        {
            for (int row = 0; row < 4; row++)
            {
                ImGui::TableNextRow();

                for (int column = 0; column < 3; column++)
                {
                    ImGui::TableSetColumnIndex(column);
                    ImGui::Text("Cell value");
                }
            }

            ImGui::EndTable();
        }

        ImGui::End();
    }

    ImGui::SetNextWindowPos(ImVec2{300.0, 300.0});
    ImGui::SetNextWindowSize(ImVec2{300.0, 150.0});

    if (ImGui::Begin("window2"))
    {
        if (ImGui::BeginTable("table2", 3, ImGuiTableFlags_Borders))
        {
            for (int row = 0; row < 4; row++)
            {
                ImGui::TableNextRow();

                for (int column = 0; column < 3; column++)
                {
                    ImGui::TableSetColumnIndex(column);
                    ImGui::Text("Cell value");
                }
            }

            ImGui::EndTable();
        }

        ImGui::End();
    }

    if (ImGui::Begin("window3"))
    {
        if (ImGui::Button("myButton", ImVec2{100.0F, 50.0F}))
        {
            std::cout << "Clicked\n";
        }

        ImGui::End();
    }

    if (ImGui::Begin("window4"))
    {
        ImPlot::CreateContext();
        ShowDemo_LinePlots();

        ImGui::End();
    }

    ImGui::Render();
}
