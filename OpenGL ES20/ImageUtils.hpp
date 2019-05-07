//
//  ImageUtils.hpp
//  OpenGL ES20
//
//  Created by 李显峰 on 2019/4/11.
//  Copyright © 2019年 xfeng. All rights reserved.
//

#ifndef ImageUtils_hpp
#define ImageUtils_hpp

#include <stdio.h>
#include <FreeImage.h>

extern FIBITMAP* loadImage(const char* pathName);
extern void freeImage(FIBITMAP* image);
#endif /* ImageUtils_hpp */
