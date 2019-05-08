//
//  MyOpenGLUtil.cpp
//  OpenGL
//
//  Created by 11 on 11/3/19.
//  Copyright © 2019年 xfeng. All rights reserved.
//

#include "MyOpenGLUtil.hpp"

bool debug = true;

extern GLint getShader(GLenum type, const GLchar* shaderSource) {
    GLuint shader = glCreateShader(type);
    if (debug) {
        printf("getShader shader : %d \n", shader);
    }
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);
    GLint status;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (debug) {
        printf("getShader status : %d \n", status);
    }
    if (!status) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::CREATE_FAILED\n" << infoLog << std::endl;
        return GL_FALSE;
    }
    return shader;
}

extern GLint genProgram(const GLchar* v_shader_source, const GLchar* f_shader_source) {
    GLint v_shader = getShader(GL_VERTEX_SHADER, v_shader_source);
    GLint f_shader = getShader(GL_FRAGMENT_SHADER, f_shader_source);
    if (v_shader == GL_FALSE || f_shader == GL_FALSE) {
        return GL_FALSE;
    }
    GLuint program = glCreateProgram();
    if (debug) {
        printf("genProgram program : %d \n", program);
    }
    glAttachShader(program, v_shader);
    glAttachShader(program, f_shader);
    glLinkProgram(program);
    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (debug) {
        printf("genProgram success : %d \n", success);
    }
    if (!success) {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        glDeleteShader(v_shader);
        glDeleteShader(f_shader);
        return GL_FALSE;
    }
    return program;
}

extern GLint genProgramFromFile(const GLchar* v_shader_path, const GLchar* f_shader_path) {
    // 1. 从文件路径中获取顶点/片段着色器
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // 保证ifstream对象可以抛出异常：
    vShaderFile.exceptions(std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::badbit);
    try
    {
        // 打开文件
        vShaderFile.open(v_shader_path);
        fShaderFile.open(f_shader_path);
        std::stringstream vShaderStream, fShaderStream;
        // 读取文件的缓冲内容到流中
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // 关闭文件
        vShaderFile.close();
        fShaderFile.close();
        // 转换流至GLchar数组
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const GLchar* vShaderCode = vertexCode.c_str();
    const GLchar* fShaderCode = fragmentCode.c_str();
    
    return genProgram(vShaderCode, fShaderCode);
}

extern GLuint genTexture(const char* imagePath, ImageType imgType) {
    GLuint textureId = 0;
    FIBITMAP* img = loadImage(imagePath);
    if (img == NULL) {
        return 0;
    }
    BYTE* imgData = FreeImage_GetBits(img);
    int w = FreeImage_GetWidth(img);
    int h = FreeImage_GetHeight(img);
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);    // Set texture wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (imgType == JPG) {
        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, imgData);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_BGR, GL_UNSIGNED_BYTE, imgData);
    }
    else if (imgType == PNG) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, imgData);
    }
    else {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, imgData);
    }
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    freeImage(img);
    return textureId;
}
