#include "Application.h"


Application::Application(int screen_X, int screen_Y)
    :board(300,300* screen_Y/screen_X)
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



        Draw(0,pos.size()/2);

        if (currenttime - prevtime >= 1 / 30.0) {
            pos.clear();
            board.UpdateBoard(&pos);
            glPointSize(1920 / 10);
            _VertexBuffers[0].AddData(&pos, pos.size());
            for (int i = 0; i < pos.size(); ++i) {
                std::cout << pos[i];
                std::cout << std::endl;
            }
            prevtime = currenttime;
        }

        /* Swap front and back buffers */
        glfwSwapBuffers(_window);

        /* Poll for and process events */

        glfwPollEvents();

    }
}

void Application::Draw(int index,int count) {



    glClear(GL_COLOR_BUFFER_BIT);

    _VertexBuffers[index].Bind();

    glPointSize(_screen_X / 300);
    glDrawArrays(GL_POINTS, 0, count);
    _VertexBuffers[0].UnBind();
}