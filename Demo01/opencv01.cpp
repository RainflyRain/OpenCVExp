//
//  opencv01.cpp
//  Demo01
//
//  Created by Fly on 2017/11/14.
//  Copyright © 2017年 Fly. All rights reserved.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv01.hpp"

using namespace cv;
using namespace std;




void showImg(){
    
    Mat webcan = imread("/Users/fly/Documents/work/WorkSpace/CWorkSpace/OpencvDemo/Demo01/timg.jpeg",IMREAD_COLOR);
    
    //复制
    Mat webcanc;
    webcan.copyTo(webcanc);
    
    //显示复制的图片
    namedWindow("copy_window",WINDOW_AUTOSIZE);
    imshow("copy_window", webcanc);
    
    //灰度处理
    Mat gray_webcat;
    cvtColor(webcan, gray_webcat, CV_BGR2GRAY);
    
    Mat resize_webcat;
    resize(webcan, resize_webcat, Size(480,640));
    
    //显示灰度图
    namedWindow("gray_img",WINDOW_AUTOSIZE);
    imshow("gray_img", gray_webcat);
    
    //二值化处理
    Mat thresImg;
    threshold(gray_webcat,thresImg,112,255,CV_THRESH_BINARY);
    
    //显示二值化图
    namedWindow("thresImg",WINDOW_AUTOSIZE);
    imshow("thresImg", thresImg);

    
    imwrite("/Users/fly/Documents/work/WorkSpace/CWorkSpace/OpencvDemo/Demo01/mz2.jpg", gray_webcat);
    
    waitKey(0);
}

