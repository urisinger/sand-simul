#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <vector>
#include "vertexbuffer.h"
#include "IndexBuffer.h"
#include "shader.h"
#include "Board.h"
static void GLclearerrors()
{
    while (glGetError());
}

static void GLCheckErrros()
{
    while (GLenum error = glGetError())
    {
        std::cout << "[opengl error](" << error << ")" << std::endl;
    }
}


class Application
{
public:
    Application(int screen_X, int scren_Y);
    ~Application() {
    };
    void GameLoop();

private:
    GLFWwindow* _window;
    int _screen_X;
    int _screen_Y;
    Board board;
    std::vector<Shader> _Shaders;
    std::vector <VertexBuffer> _VertexBuffers;
    std::vector <IndexBuffer> _IndexBuffers;


    void Draw(void* pos,int index, int count);
};

