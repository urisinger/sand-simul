#include "shader.h"


Shader::Shader(const std::string& vertex_file_path, const std::string& fragment_file_path)
{
    // Create the shader program
    Renderer_ID = glCreateProgram();

    // Compile the vertex and fragment shaders
    unsigned int vertex_shader = CompileShader(GL_VERTEX_SHADER, OpenShader(vertex_file_path));
    unsigned int fragment_shader = CompileShader(GL_FRAGMENT_SHADER, OpenShader(fragment_file_path));

    // Attach the shaders to the program and link it
    glAttachShader(Renderer_ID, vertex_shader);
    glAttachShader(Renderer_ID, fragment_shader);
    glLinkProgram(Renderer_ID);
    glValidateProgram(Renderer_ID);


    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    // Get the location of the "u_color" uniform
    location = glGetUniformLocation(Renderer_ID, "u_color");

    // Set the initial value of the "u_color" uniform
    glUniform4f(location, 1.0f, 1.0f, 1.0f, 1.0f);
}

void Shader::bind() {
    glUseProgram(Renderer_ID);
}

void Shader::unbind() {
    glUseProgram(0);
}


void Shader::SetUniform(float f1, float f2, float f3, float f4) {
    glUniform4f(location, f1, f2, f3, f4);
}


Shader::~Shader() {
    glDeleteProgram(Renderer_ID);
}



std::string Shader::OpenShader(std::string filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if (!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while (!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* messge = (char*)_malloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, messge);
        std::cout << "failt to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
        std::cout << messge << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}



