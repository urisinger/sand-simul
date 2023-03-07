#include "Application.h"


Application::Application(int screen_X, int screen_Y)
    :board(100,100)
{

    _screen_X = screen_X;
    _screen_Y = screen_Y;
    /* Initialize the library */
    _ASSERT(glfwInit());
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
            board.UpdateBoard(&pos, _screen_X, _screen_Y);
            prevtime = currenttime;
        }
        Draw(&pos,pos.size());
        /* Swap front and back buffers */
        glfwSwapBuffers(_window);

        /* Poll for and process events */

        glfwPollEvents();

    }
}

void Application::Draw(void* pos,unsigned int size) {

    glPointSize(100);
    
    _VertexBuffers[0].AddData(pos, size);

    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_POINTS, 0, 1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}