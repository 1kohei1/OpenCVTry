//
//  ViewController.m
//  OpenCVTry
//
//  Created by Kohei Arai on 9/16/14.
//  Copyright (c) 2014 Kohei Arai. All rights reserved.
//

#import "ViewController.h"
#import "ImageHandler.h"
#import <opencv2/imgcodecs/ios.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    ImageHandler *imageHandler = [[ImageHandler alloc]init];
    UIImage *originalImage, *grayImage;
    cv::Mat originalImageMat, grayImageMat;
    
    originalImage = [UIImage imageNamed:@"OCR_Test1_Original.JPG"];
    originalImageMat = [imageHandler cvMatFromUIImage:originalImage];
    cv::cvtColor(originalImageMat, grayImageMat, CV_RGBA2GRAY);
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
