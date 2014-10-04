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
    
    UIImage *image = [UIImage imageNamed:@"lena.png"];
    
    // Convert to UIImage to cv::Mat
    cv::Mat cvImage;
    UIImageToMat(image, cvImage);
    
    if (!cvImage.empty()) {
        cv::Mat gray;
        
        // Convert the image to gray scale
        cv::cvtColor(cvImage, gray, CV_RGBA2GRAY);
        // Apply Gaussian filter to remove small edges
        cv::GaussianBlur(gray, gray, cv::Size(5, 5), 1.2);
        // Calculate edges with Canny
        cv::Mat edges;
        cv::Canny(gray, edges, 0, 50);
        // Fill image with white color
        cvImage.setTo(cv::Scalar::all(255));
        // Change color on edges
        cvImage.setTo(cv::Scalar(0, 0, 255, 255), edges);
        // Convert cv::Mat to UIImage* and show the resulting image
        self.imageView.image = MatToUIImage(cvImage);
    }
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
