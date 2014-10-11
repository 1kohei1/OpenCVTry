//
//  RetroFilter.cpp
//  OpenCVTry
//
//  Created by Kohei Arai on 10/10/14.
//  Copyright (c) 2014 Kohei Arai. All rights reserved.
//

#include "OpenCVConstants.h"
#include "RetroFilter.h"

void alphaBlendC1(cv::Mat src, cv::Mat dst, cv::Mat alpha) {
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            uchar alphaVal = alpha.at<uchar>(i, j);
            if (alphaVal != 0) {
                float weight = static_cast<float>(alphaVal) / 255.0f;
                dst.at<uchar>(i, j) = weight * src.at<uchar>(i, j) + (1 - weight) *dst.at<uchar>(i, j);
            }
        }
    }
}

RetroFilter::RetroFilter(const Parameters& params):rng_(time(0)) {
    params_ = params;
    
    multiplier_ = 1.0;
    
    borderColor_ = cv::Mat(params_.frameSize, CV_8UC1);
    scratchColor_ = cv::Mat(params_.frameSize, CV_8UC1);
    
    sepiaH_ = cv::Mat(params_.frameSize, CV_8UC1);
    sepiaH_.setTo(cv::Scalar(19));
    
    sepiaS_ = cv::Mat(params_.frameSize, CV_8UC1);
    sepiaS_.setTo(cv::Scalar(78));
    
    sepiaPlanes_.resize(3);
    sepiaPlanes_[0] = sepiaH_;
    sepiaPlanes_[1] = sepiaS_;
    
    cv::resize(params_.fuzzyBorder, params_.fuzzyBorder, params_.frameSize);
    if (params_.scratches.rows < params_.frameSize.height || params_.scratches.cols < params_.frameSize.width) {
        cv::resize(params_.scratches, params_.scratches, params_.frameSize);
    }
}

void RetroFilter::applyToPhoto(const cv::Mat& frame, cv::Mat& retroFrame) {
    cv::Mat luminance;
    cv::cvtColor(frame, luminance, CV_BGR2GRAY);
    
    // Add scratches
    cv::Scalar meanColor = mean(luminance.row(luminance.rows / 2));
    scratchColor_.setTo(meanColor * 2.0);
    int x = rng_.uniform(0, params_.scratches.cols - luminance.cols);
    int y = rng_.uniform(0, params_.scratches.rows - luminance.rows);
    cv::Rect roi = cv::Rect(cv::Point(x, y), luminance.size());
    alphaBlendC1(scratchColor_, luminance, params_.scratches(roi));

    // Add fuzzy border
    borderColor_.setTo(meanColor * 1.5);
    alphaBlendC1(borderColor_, luminance, params_.fuzzyBorder);

    // Apply sepia-effect
    sepiaPlanes_[2] = luminance + 20;
    cv::Mat hsvFrame;
    cv::merge(sepiaPlanes_, hsvFrame);
    cv::cvtColor(hsvFrame, retroFrame, CV_HSV2RGB);
}




