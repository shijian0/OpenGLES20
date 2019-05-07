//
//  MyTriangle.hpp
//  OpenGL
//
//  Created by 11 on 9/3/19.
//  Copyright © 2019年 xfeng. All rights reserved.
//

#ifndef MyTriangle_hpp
#define MyTriangle_hpp

#include <stdio.h>
#include <GLUT/GLUT.h>
#include "MyOpenGLUtil.hpp"
class MyTriangle {
private:
    GLint mProgram = GL_FALSE;
    GLint ver_handle;
    GLint tex_handle;
    
    GLuint textureId;
    // Shaders
    const GLchar* vertexShaderSource =
    //"#version 230 core\n"
    //"layout (location = 0) in vec3 position;\n"
    "attribute vec4 a_Position;\n"
    "attribute vec2 a_Textposition;\n"
    "varying vec2 vTextureCoord;\n"
    "void main()\n"
    "{\n"
    "gl_Position = a_Position;\n"
    "vTextureCoord = a_Textposition;\n"
    //"gl_Position = vec4(1.0, 1.0, 1.0, 0.0);\n"
    "}\0";
    const GLchar* fragmentShaderSource =
    //"#version 230 core\n"
    "varying vec2 vTextureCoord;\n"
    "uniform sampler2D sTexture;\n"
    "void main()\n"
    "{\n"
    "gl_FragColor = texture2D(sTexture, vTextureCoord);"
    "}\0";
    
public:
    void initProgram();
    void initData();
    int draw();
};

#endif /* MyTriangle_hpp */
