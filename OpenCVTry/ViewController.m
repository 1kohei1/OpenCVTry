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
    
    /****************************** Face Detection */
    // Load cascade classifier from the XML file
    NSString *cascadePath = [[NSBundle mainBundle] pathForResource:@"haarcascade_frontalface_alt2" ofType:@"xml"];
    faceDetector.load([cascadePath UTF8String]);
    
    // Load image with face
    UIImage *image = [UIImage imageNamed:@"group_of_people_faces.jpg"];
    cv::Mat faceImage;
    UIImageToMat(image, faceImage);
    
    // Convert to grayscale
    cv::Mat gray;
    cv::cvtColor(faceImage, gray, CV_BGR2GRAY);
    
    // Detect faces
    std::vector<cv::Rect> faces;
    std::vector<cv::Mat> faceImages;
    faceDetector.detectMultiScale(gray, faces);
    
    // Draw all detected faces
    for (unsigned int i = 0; i < faces.size(); i++) {
        cv::Mat cutImage;
        const cv::Rect face = faces[i];
        // Get top-left and bottom-right corner points
        
        cv::Point tl(face.x, face.y);
        cv::Point br = tl + cv::Point(face.width, face.height);
        
        // Draw rectangle around the face
        cv::Scalar magenta = cv::Scalar(255, 0, 255);
        cv::rectangle(faceImage, tl, br, magenta, 4, 8, 0);
        
        // Cut image and store it to the array
        faceImage(face).copyTo(cutImage);
        faceImages.push_back(cutImage);
    }

    // Show resulting image
    NSLog(@"%lu", faceImages.size());
    self.imageView.image = MatToUIImage(faceImages[2]);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) pastCode {
    /******************************
    // Highlight edges
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
     ******************************/
    
    /****************************** Create a Postcard
    PostcardPrinter::Parameters params;
    
    UIImage* image = [UIImage imageNamed:@"lena.png"];
    UIImageToMat(image, params.face);
    
    image = [UIImage imageNamed:@"texture.jpg"];
    UIImageToMat(image, params.texture);
    cvtColor(params.texture, params.texture, CV_RGBA2RGB);
    
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
        self.imageView.image = MatToUIImage(postcard);
     ******************************/
    
    /****************************** Sudoku Practice
     NSString *sudoku = @"sudoku_img.jpg";
     NSString *ocr = @"OCR_Test1_Original.jpg";
     NSString *lena = @"lena.png";
     
     UIImage *sudokuImg = [UIImage imageNamed:sudoku];
     cv::Mat cvImage;
     UIImageToMat(sudokuImg, cvImage);
     
     if (cvImage.empty())
     return;
     
     // Begin to measure time
     int64 timeStart = cv::getTickCount();
     
     cv::Mat sudokuGray;
     cv::cvtColor(cvImage, sudokuGray, CV_RGBA2GRAY); // Black and white
     cv::GaussianBlur(sudokuGray, sudokuGray, cv::Size(5, 5), 1.2); //Gaussian filter
     cv::adaptiveThreshold(sudokuGray, sudokuGray, 500, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 3, 0); // Threshold
     
     // Finish to measure time
     int64 timeEnd = cv::getTickCount();
     float durationMs = 1000.f * float(timeEnd - timeStart) / cv::getTickFrequency();
     NSLog(@"Time = %.3fms", durationMs);
     
     self.imageView.image = MatToUIImage(sudokuGray);
     ******************************/

}

@end