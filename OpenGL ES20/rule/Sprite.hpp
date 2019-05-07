//
//  Sprite.hpp
//  OpenGL ES20
//
//  Created by 李显峰 on 2019/5/6.
//  Copyright © 2019年 xfeng. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <stdio.h>
#include <vector>
#include "XFrame.hpp"

using namespace std;

class Sprite {
public:
    Sprite(vector<char*> imgPaths);
    int draw();
private:
//    XFrame frames[5] = {XFrame("/Users/lixianfeng/Desktop/gles/img11.jpg"),
//        XFrame("/Users/lixianfeng/Desktop/gles/img12.jpg"),
//        XFrame("/Users/lixianfeng/Desktop/gles/img13.jpg"),
//        XFrame("/Users/lixianfeng/Desktop/gles/img14.jpg"),
//        XFrame("/Users/lixianfeng/Desktop/gles/img15.jpg")};
    vector<XFrame> frames;
    int curFrame = 0;
    int frameCount = 0;
};


#endif /* Sprite_hpp */
