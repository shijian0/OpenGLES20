//
//  main.cpp
//  OpenGL
//
//  Created by 11 on 7/11/18.
//  Copyright © 2018年 xfeng. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
#include "MyTriangle.hpp"
#include "Sprite.hpp"

void timer(int time);
void drawTriangle();
MyTriangle* triangle = nullptr;

void drawSprite();
Sprite* sprite = nullptr;

void display()
{
    glViewport(0, 0, 100, 100);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    //    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}

int main(int argc, char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    glutInit(&argc, argv);
    glutCreateWindow("XCode window");
    glViewport(0, 0, 100, 100);
    const GLubyte * version = glGetString(GL_VERSION);
    printf("opengl version is %s", version);
    glutDisplayFunc(drawSprite);
    glutTimerFunc(300, timer, 300);
    glutMainLoop();
    
    return 0;
}

static int extracted() {
    return triangle->draw();
}

void drawTriangle() {
    if(!triangle){
        triangle = new MyTriangle();
        triangle->initProgram();
        triangle->initData();
    }
    extracted();
}

void drawSprite() {
    if (!sprite) {
        vector<char*> imgPaths;
        
//        imgPaths.push_back("/Users/lixianfeng/Desktop/gles/img11.jpeg");
//        imgPaths.push_back("/Users/lixianfeng/Desktop/gles/img12.jpg");
//        imgPaths.push_back("/Users/lixianfeng/Desktop/gles/img13.jpg");
//        imgPaths.push_back("/Users/lixianfeng/Desktop/gles/img14.jpg");
//        imgPaths.push_back("/Users/lixianfeng/Desktop/gles/img15.jpg");
        
        imgPaths.push_back("/Users/a11/test/opengl/img1.png");
        imgPaths.push_back("/Users/a11/test/opengl/img2.png");
        imgPaths.push_back("/Users/a11/test/opengl/img3.png");
        imgPaths.push_back("/Users/a11/test/opengl/img4.png");
        imgPaths.push_back("/Users/a11/test/opengl/img5.png");
        
        sprite = new Sprite(imgPaths);
    }
    sprite->draw();
}

int mCount = 0;
void timer(int time) {
    glutTimerFunc(300, timer, 0);
    glutPostRedisplay();
    printf("timer %d \n", mCount ++);
}
