//
//  ImageHandler.h
//  OpenCVTry
//
//  Created by Kohei Arai on 9/27/14.
//  Copyright (c) 2014 Kohei Arai. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ImageHandler : NSObject

- (cv::Mat)cvMatFromUIImage:(UIImage *)image;
- (cv::Mat)cvMatGrayFromUIImage:(UIImage *)image;
-(UIImage *)UIImageFromCVMat:(cv::Mat)cvMat;

@end
