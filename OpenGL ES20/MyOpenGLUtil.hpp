//
//  MyOpenGLUtil.hpp
//  OpenGL
//
//  Created by 11 on 11/3/19.
//  Copyright © 2019年 xfeng. All rights reserved.
//

#ifndef MyOpenGLUtil_hpp
#define MyOpenGLUtil_hpp
#include <GLUT/GLUT.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ImageUtils.hpp"

extern GLint getShader(GLenum type, const GLchar*);
//extern GLint genProgram();
extern GLint genProgram(const GLchar* v_shader_source, const GLchar* f_shader_source);

extern GLint genProgramFromFile(const GLchar* v_shader_path, const GLchar* f_shader_path);
//生成纹理
extern GLuint genTexture(const char* );
#endif /* MyOpenGLUtil_hpp */
