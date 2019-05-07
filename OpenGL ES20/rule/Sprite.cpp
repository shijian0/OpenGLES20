//
//  Sprite.cpp
//  OpenGL ES20
//
//  Created by 李显峰 on 2019/5/6.
//  Copyright © 2019年 xfeng. All rights reserved.
//

#include "Sprite.hpp"

Sprite::Sprite(vector<char*> imgPaths) {
    frameCount = imgPaths.size();
    for (int i = 0; i < frameCount; i ++) {
        frames.push_back(XFrame(imgPaths[i]));
        
    }
    
}

int Sprite::draw() {
    for (int i = 0; i < frameCount; i ++) {
        if (i == curFrame) {
            frames[i].draw();
            curFrame ++;
            break;
        }
        
    }
    if (curFrame >= frameCount) {
        curFrame = 0;
    }
    return 0;
}
