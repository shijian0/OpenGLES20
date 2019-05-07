//
//  XFrame.hpp
//  OpenGL ES20
//
//  Created by 李显峰 on 2019/5/6.
//  Copyright © 2019年 xfeng. All rights reserved.
//

#ifndef XFrame_hpp
#define XFrame_hpp

#include <stdio.h>
#include <GLUT/GLUT.h>
#include "MyOpenGLUtil.hpp"

class XFrame {
public:
    XFrame(char* imagePath);
    int draw();
private:
    GLint mProgram = GL_FALSE;
    GLint ver_handle;
    GLint tex_handle;
    GLuint textureId;
    
};

#endif /* XFrame_hpp */
