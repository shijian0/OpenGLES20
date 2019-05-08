//
//  MyTriangle.cpp
//  OpenGL
//
//  Created by 11 on 9/3/19.
//  Copyright © 2019年 xfeng. All rights reserved.
//

#include "MyTriangle.hpp"

GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f, // Left
    -0.5f, 0.5f, 0.0f, // Right
    0.5f,  0.5f, 0.0f,  // Top
    0.5f, -0.5f, 0.0f
};

GLfloat textures[] = {
    
    0.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    
};

void MyTriangle::initProgram() {
    //    program = genProgram(vertexShaderSource, fragmentShaderSource);
    mProgram = genProgramFromFile("/Users/lixianfeng/Desktop/gles/triangle_ver_shader", "/Users/lixianfeng/Desktop/gles/triangle_frg_shader");
}

void MyTriangle::initData() {
    textureId = genTexture("/Users/lixianfeng/Desktop/gles/img.jpg", JPG);
}

int MyTriangle::draw() {
    
    if (mProgram != GL_FALSE) {
        glClear(GL_COLOR_BUFFER_BIT);
        GLuint ver_handle = glGetAttribLocation(mProgram, "v_position");
        GLuint tex_handle = glGetAttribLocation(mProgram, "intex_position");
        
        glUseProgram(mProgram);
        
        glVertexAttribPointer(ver_handle, 3, GL_FLOAT, GL_FALSE, 0, vertices);
        glVertexAttribPointer(tex_handle, 2, GL_FLOAT, GL_FALSE, 0, textures);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glUniform1f(textureId, 0);
        
        glEnableVertexAttribArray(tex_handle);
        glEnableVertexAttribArray(ver_handle);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glFlush();
    }
    return 0;
}
