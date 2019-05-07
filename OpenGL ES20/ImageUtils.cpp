//
//  ImageUtils.cpp
//  OpenGL ES20
//
//  Created by 李显峰 on 2019/4/11.
//  Copyright © 2019年 xfeng. All rights reserved.
//

#include "ImageUtils.hpp"

extern FIBITMAP* loadImage(const char* pathName) {
    FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
    
    fif = FreeImage_GetFileType(pathName);
    
    if(fif == FIF_UNKNOWN)
        fif  =  FreeImage_GetFIFFromFilename(pathName);
    if((fif != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif))
    {
        FIBITMAP *dib = FreeImage_Load(fif, pathName);
        return dib;
    }
    return NULL;
}

extern void freeImage(FIBITMAP* image) {
    if (image) {
        FreeImage_Unload(image);
    }
}
