//
//  XFrame.cpp
//  OpenGL ES20
//
//  Created by 李显峰 on 2019/5/6.
//  Copyright © 2019年 xfeng. All rights reserved.
//

#include "XFrame.hpp"

GLfloat frame_vertices[] = {
    -0.5f, -0.5f, 0.0f, // Left
    -0.5f, 0.5f, 0.0f, // Right
    0.5f,  0.5f, 0.0f,  // Top
    0.5f, -0.5f, 0.0f
};

GLfloat frame_textures[] = {
    
    0.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    
};

XFrame::XFrame(char* imagePath) {
    mProgram = genProgramFromFile("/Users/lixianfeng/Desktop/gles/triangle_ver_shader", "/Users/lixianfeng/Desktop/gles/triangle_frg_shader");
    textureId = genTexture(imagePath);
}

int XFrame::draw() {
    
    if (mProgram != GL_FALSE) {
        glClear(GL_COLOR_BUFFER_BIT);
        GLuint ver_handle = glGetAttribLocation(mProgram, "v_position");
        GLuint tex_handle = glGetAttribLocation(mProgram, "intex_position");
        
        glUseProgram(mProgram);
        
        glVertexAttribPointer(ver_handle, 3, GL_FLOAT, GL_FALSE, 0, frame_vertices);
        glVertexAttribPointer(tex_handle, 2, GL_FLOAT, GL_FALSE, 0, frame_textures);
        
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
