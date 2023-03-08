#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>
#include <fstream>


#include "headers/vertexbuffer.h"
#include "headers/IndexBuffer.h"

#include "headers/Application.h"


int main(void)
{
    Application App(1000,1000);
    App.GameLoop();
    return 0;
}