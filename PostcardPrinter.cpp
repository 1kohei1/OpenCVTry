//
//  PostcardPrinter.cpp
//  OpenCVTry
//
//  Created by Kohei Arai on 10/4/14.
//  Copyright (c) 2014 Kohei Arai. All rights reserved.
//

#include "OpenCVConstants.h"
#include "PostcardPrinter.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

PostcardPrinter::PostcardPrinter(Parameters& params) {
    params_ = params;

    markup();
}

void PostcardPrinter::markup() {
    // Prepare postcard
    int unit = 320;
    cv::Size postcardSize = cv::Size(2 * unit, 3 * unit);
    int border = unit / 8;
    
    // Resize all input images properly
    resize(params_.texture, params_.texture, postcardSize);
    resize(params_.face, params_.face,
           cv::Size(postcardSize.width - 2 * border,
                    postcardSize.width - 2 * border));
    cv::Size newTextSz;
    newTextSz.width = params_.face.cols * 0.9;
    newTextSz.height = newTextSz.width * params_.text.rows / params_.text.cols;
    resize(params_.text, params_.text, newTextSz);
    
    // Choose places for face and text
    cv::Point shift(border, 2 * border);
    faceRoi_ = cv::Rect(shift, params_.face.size());
    
    cv::Point origin(border + params_.face.cols * 0.05,
                     params_.face.rows + 4.5 * border);
    textRoi_ = cv::Rect(origin, params_.text.size());
}

void PostcardPrinter::printFragment(Mat& placeForFragment,
                                    const Mat& fragment) const {
    // Get alpha channel
    vector<Mat> fragmentPlanes;
    split(fragment, fragmentPlanes); // divide mat into channel blue, green, red, alpha
    CV_Assert(fragmentPlanes.size() == 4); // check if there are 4 channels
    
    Mat alpha = fragmentPlanes[3]; // get alpha channel
    fragmentPlanes.pop_back(); // drop alpha channel from the fragmentPlanes
    Mat bgrFragment; // create a variable to store blue, green, red channel
    merge(fragmentPlanes, bgrFragment); // set blue, green, red channel into one mat called bgrFragment
    
    // Add fragment with crumpling and plane
    crumple(bgrFragment, placeForFragment, alpha);
    alphaBlendC3(bgrFragment, placeForFragment, alpha);
}

void PostcardPrinter::print(Mat& postcard) const {
    postcard = params_.texture.clone();
    
    Mat placeForFace = postcard(faceRoi_);
    Mat placeForText = postcard(textRoi_);

    printFragment(placeForFace, params_.face);
//    printFragment(placeForText, params_.text);
}

void PostcardPrinter::crumple(Mat& image, const Mat& texture,
                              const Mat& mask) const
{
    Mat relief;
    cvtColor(texture, relief, CV_BGR2GRAY);
    relief = 255 - relief;
    
    Mat hsvImage;
    cvtColor(image, hsvImage, CV_BGR2HSV);
    
    vector<Mat> planes;
    split(hsvImage, planes);
    CV_Assert(planes.size() == 3);
    subtract(planes[2], relief, planes[2], mask);
    merge(planes, hsvImage);
    
    cvtColor(hsvImage, image, CV_HSV2BGR);
}

void PostcardPrinter::alphaBlendC3(const Mat& src, Mat& dst,
                                   const Mat& alpha) const
{
    for (int i = 0; i < src.rows; i++)
        for (int j = 0; j < src.cols; j++)
        {
            uchar alpha_value = alpha.at<uchar>(i, j);
            if (alpha_value != 0)
            {
                float weight = float(alpha_value) / 255.f;
                dst.at<Vec3b>(i, j) = weight * src.at<Vec3b>(i, j) + (1 - weight) * dst.at<Vec3b>(i, j);
            }
        }
}

