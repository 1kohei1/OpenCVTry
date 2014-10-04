//
//  ViewController.m
//  OpenCVTry
//
//  Created by Kohei Arai on 9/16/14.
//  Copyright (c) 2014 Kohei Arai. All rights reserved.
//

#import "ViewController.h"
#import "OpenCVConstants.h"
#import "PostcardPrinter.hpp"
#import <opencv2/imgcodecs/ios.h>

@interface ViewController ()

@end

@implementation ViewController

- (NSUInteger)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    /*
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
     */
    
    
    PostcardPrinter::Parameters params;
    
    // Load image with face
    UIImage* image = [UIImage imageNamed:@"lena.png"];
    UIImageToMat(image, params.face);
    
    // Load image with texture
    image = [UIImage imageNamed:@"texture.jpg"];
    UIImageToMat(image, params.texture);
    cvtColor(params.texture, params.texture, CV_RGBA2RGB);
    
    // Load image with text
    image = [UIImage imageNamed:@"text.png"];
    UIImageToMat(image, params.text, true);
    
    // Create PostcardPrinter class
    PostcardPrinter postcardPrinter(params);
    
    // Print postcard, and measure printing time
    cv::Mat postcard;
    int64 timeStart = cv::getTickCount();
    postcardPrinter.print(postcard);
    int64 timeEnd = cv::getTickCount();
    float durationMs =
    1000.f * float(timeEnd - timeStart) / cv::getTickFrequency();
    NSLog(@"Printing time = %.3fms", durationMs);
    
    if (!postcard.empty())
        self.imageView.image = MatToUIImage(postcard);}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
