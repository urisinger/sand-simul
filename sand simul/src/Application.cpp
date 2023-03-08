#include "headers/Application.h"


Application::Application(int screen_X, int screen_Y)
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


        Draw(pos.data(), 0, pos.size() / 2);
        prevtime = currenttime;
        /* Swap front and back buffers */
        glfwSwapBuffers(_window);
        
        /* Poll for and process events */

        glfwPollEvents();

    }
}

void Application::Draw(void* pos, int index, int count) {



    glClear(GL_COLOR_BUFFER_BIT);

    _VertexBuffers[index].Bind();

    _VertexBuffers[index].AddData(pos,count*2);


    glPointSize(_screen_X / 300.0);
    glDrawArrays(GL_POINTS, 0, count);
    _VertexBuffers[index].UnBind();
}