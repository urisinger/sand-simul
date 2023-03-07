#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>
#include <fstream>


#include "vertexbuffer.h"
#include "IndexBuffer.h"

#include "Application.h"


int main(void)
{
    Application App(1920,1080);
    App.GameLoop();
    return -1;
}