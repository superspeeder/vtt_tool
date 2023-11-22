#include "vtt.hpp"

#define GLSL_VERSION "#version 460 core"

using namespace gl;

namespace vtt {
    VTT::VTT() {
        glfwInit();

        glfwWindowHint(GLFW_RESIZABLE, true);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        m_Window = glfwCreateWindow(1024, 768, "VTT", nullptr, nullptr);

        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1);

        glbinding::initialize(glfwGetProcAddress);

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls

        glfwGetWindowContentScale(m_Window, &io.FontGlobalScale, nullptr);

        io.Fonts->AddFontFromFileTTF("Roboto/Roboto-Regular.ttf", 16);

        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
        ImGui_ImplOpenGL3_Init(GLSL_VERSION);
    }

    VTT::~VTT() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void VTT::run() {
        while (!glfwWindowShouldClose(m_Window)) {
            glfwPollEvents();


            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            drawUI();

            ImGui::Render();

            int display_w, display_h;
            glfwGetFramebufferSize(m_Window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(m_Window);
        }
    }

    void VTT::drawUI() {
        ImGui::ShowDemoWindow(nullptr);
    }
}

int main() {

    vtt::VTT app{};
    app.run();

    return EXIT_SUCCESS;
}