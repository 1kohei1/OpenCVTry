//
//  RetroFilter.h
//  OpenCVTry
//
//  Created by Kohei Arai on 10/10/14.
//  Copyright (c) 2014 Kohei Arai. All rights reserved.
//
#pragma once

#ifndef __OpenCVTry__RetroFilter__
#define __OpenCVTry__RetroFilter__

#include <stdio.h>
#include "opencv2/core/core.hpp"


void alphaBlendC1(cv::Mat src, cv::Mat dst, cv::Mat alpha);

class RetroFilter {
public:
    struct Parameters {
        cv::Size frameSize;
        cv::Mat fuzzyBorder;
        cv::Mat scratches;
    };
    
    RetroFilter(const Parameters& params);
    virtual ~RetroFilter() {};
    void applyToPhoto(const cv::Mat& frame, cv::Mat& retroFrame);
    
protected:
    Parameters params_;
    
    cv::RNG rng_;
    float multiplier_;
    
    cv::Mat borderColor_;
    cv::Mat scratchColor_;
    
    std::vector<cv::Mat> sepiaPlanes_;
    cv::Mat sepiaH_;
    cv::Mat sepiaS_;
};

#endif /* defined(__OpenCVTry__RetroFilter__) */
