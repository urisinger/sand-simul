#include "Application.h"


Application::Application(int screen_X, int screen_Y)
    :board(10,10)
{

    _screen_X = screen_X;
    _screen_Y = screen_Y;
    /* Initialize the library */
    glfwInit();
    /* Create a windowed mode window and its OpenGL context */
    _window = glfwCreateWindow(screen_X, screen_Y, "Hello World", NULL, NULL);
    _ASSERT(_window);
    /* Make the window's context current */
    glfwMakeContextCurrent(_window);
    
    glfwSwapInterval(1);
    if (glewInit() != GLEW_OK) {
        std::cout << "error!" << std::endl;
    }

    _Shaders.emplace_back("res/shader/vertex.shader", "res/shader/fragment.shader");
    _VertexBuffers.emplace_back();

}

void Application::GameLoop() {
    std::vector <float> pos;
    double prevtime=0;
    double currenttime=0;
    while (!glfwWindowShouldClose(_window)) {
        GLclearerrors();
        currenttime = glfwGetTime();
        if (currenttime - prevtime >= 1) {
            pos.clear();
            board.UpdateBoard(&pos, _screen_X, _screen_Y);
            prevtime = currenttime;


        }

        for (int i = 0; i < pos.size(); ++i) {
            std::cout << pos[i];
            std::cout << std::endl;
        }
        Draw(&pos,pos.size());
        /* Swap front and back buffers */
        glfwSwapBuffers(_window);

        /* Poll for and process events */

        glfwPollEvents();

    }
}

void Application::Draw(void* pos,unsigned int size) {



    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(1920 / 100);

    _VertexBuffers[0].AddData(pos, size);

    glDrawArrays(GL_POINTS, 0, size);
}