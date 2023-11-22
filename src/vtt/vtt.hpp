#pragma once

#define GLFW_INCLUDE_NONE

#include <glbinding/glbinding.h>
#include <glbinding/gl/gl.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <spdlog/spdlog.h>

#include <imgui.h>
#include <imgui_freetype.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace vtt {
    class VTT {
    public:

        VTT();
        ~VTT();

        void run();

    private:
        GLFWwindow* m_Window;

        glm::vec4 m_ClearColor{0.0f,0.0f,0.0f,1.0f};

        void drawUI();
    };
}