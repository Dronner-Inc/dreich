#include "renderer/shader.hpp"

// clang-format off
#include <glm/gtc/type_ptr.hpp>
#include <spdlog/spdlog.h>
// clang-formaton


namespace wind {

Shader::Shader(const char *_vsh, const char *_fsh) {
    int success;
    char msg[512];

    // Vertex
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &_vsh, NULL);
    glCompileShader(vs);

    glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vs, 512, NULL, msg);
        spdlog::error("Failed compile vertex shader: {}", msg);
        return;
    }

    // Fragment
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &_fsh, NULL);
    glCompileShader(fs);

    glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fs, 512, NULL, msg);
        spdlog::error("Failed compile fragment shader: {}", msg);
        return;
    }

    // Program
    m_program = glCreateProgram();
    glAttachShader(m_program, vs);
    glAttachShader(m_program, fs);
    glLinkProgram(m_program);

    glGetShaderiv(m_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(m_program, 512, NULL, msg);
        spdlog::error("Failed link shader: {}", msg);
        return;
    }

    glDeleteShader(vs);
    glDeleteShader(fs);
}

Shader::~Shader() {
    glDeleteProgram(m_program);
}

void Shader::use() {
    glUseProgram(m_program);
}

void Shader::uFloatArray(const char *_name, size_t _size, float *_arr) {
    int loc = glGetUniformLocation(m_program, _name);
    glUniform1fv(loc, _size, _arr);
}

void Shader::uMat4f(const char *_name, glm::mat4 _mat) {
    int loc = glGetUniformLocation(m_program, _name);
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(_mat));
}

void Shader::uInt(const char *_name, int _i) {
    int loc = glGetUniformLocation(m_program, _name);
    glUniform1i(loc, _i);
}

void Shader::uVec4f(const char* name, glm::vec4 _vec) {
    int loc = glGetUniformLocation(m_program, name);
    glUniform4f(loc, _vec.r, _vec.g, _vec.b, _vec.a);
}

void Shader::uVec2f(const char *_name, glm::vec2 _vec) {
    int loc = glGetUniformLocation(m_program, _name);
    glUniform2f(loc, _vec.x, _vec.y);
}

} // namespace wind
