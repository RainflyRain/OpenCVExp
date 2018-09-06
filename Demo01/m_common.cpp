//
//  ColorMain.cpp
//  Demo01
//
//  Created by Fly on 2017/8/6.
//  Copyright © 2017年 Fly. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

using namespace cv;
using namespace std;

//1、截屏并显示
void ShowCaptrue(){
    
    while (true) {
        VideoCapture cap(0);
        Mat webcan;
        cap.read(webcan);
        
        namedWindow("dispaly img",WINDOW_AUTOSIZE);
        imshow("webcan", webcan);
        
        waitKey(10);

    }
    
}

//2、颜色识别
int ColorRecognize(){
    //截取视频帧
    VideoCapture cap(0);
    
    //创建window窗口 control
    namedWindow("Control", CV_WINDOW_AUTOSIZE);
    
    int iLowH = 100;
    int iHighH = 140;
    
    int iLowS = 90;
    int iHighS = 255;
    
    int iLowV = 90;
    int iHighV = 255;
    
    //在controlwindow中创建trackbar控制器
    cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
    cvCreateTrackbar("HighH", "Control", &iHighH, 179);
    
    cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    cvCreateTrackbar("HighS", "Control", &iHighS, 255);
    
    cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
    cvCreateTrackbar("HighV", "Control", &iHighV, 255);
    
    while (true)
    {
        Mat imgOriginal;
        
        bool bSuccess = cap.read(imgOriginal); // read a new frame from video
        
        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }
        
        Mat imgHSV;
        vector<Mat> hsvSplit;
        //转换截图RGB 为 HSV
        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);
        
        //因为我们读取的是彩色图，直方图均衡化需要在HSV空间做
        split(imgHSV, hsvSplit);
        equalizeHist(hsvSplit[2],hsvSplit[2]);
        merge(hsvSplit,imgHSV);
        Mat imgThresholded;
        
        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
        
        //开操作 (去除一些噪点)
        Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
        morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
        
        //闭操作 (连接一些连通域)
        morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
        
        imshow("Thresholded Image", imgThresholded); //show the thresholded image
        imshow("Original", imgOriginal); //show the original image
        
        char key = (char) waitKey(300);
        if(key == 27)
            break;
    }
    
    return 0;

}


//3、特征点
void drawCornerOnImage(Mat& image,const Mat&binary)
{
    Mat_<uchar>::const_iterator it=binary.begin<uchar>();
    Mat_<uchar>::const_iterator itd=binary.end<uchar>();
    for(int i=0;it!=itd;it++,i++)
    {
        if(*it)
            circle(image,Point(i%image.cols,i/image.cols),3,Scalar(0,255,0),1);
    }
}
void FeaturePoint(){
    
    
    while (true) {
        VideoCapture cap(0);
        Mat image;
        cap.read(image);
        Mat gray;
        cvtColor(image,gray,CV_BGR2GRAY);
        
        Mat cornerStrength;
        cornerHarris(gray,cornerStrength,3,3,0.01);
        
        double maxStrength;
        double minStrength;
        // 找到图像中的最大、最小值
        minMaxLoc(cornerStrength,&minStrength,&maxStrength);
        
        Mat dilated;
        Mat locaMax;
        // 膨胀图像，最找出图像中全部的局部最大值点
        dilate(cornerStrength,dilated,Mat());
        // compare是一个逻辑比较函数，返回两幅图像中对应点相同的二值图像
        compare(cornerStrength,dilated,locaMax,CMP_EQ);
        
        Mat cornerMap;
        double qualityLevel=0.01;
        double th=qualityLevel*maxStrength; // 阈值计算
        threshold(cornerStrength,cornerMap,th,255,THRESH_BINARY);
        cornerMap.convertTo(cornerMap,CV_8U);
        // 逐点的位运算
        bitwise_and(cornerMap,locaMax,cornerMap);
        
        drawCornerOnImage(image,cornerMap);
        namedWindow("result");
        imshow("result",image);
        
        char key = (char) waitKey(1);
        if(key == 27)
            break;

        
    }
    
    
}

//4、轮廓

#define WINDOWN_1 "原图"
#define WINDOWN_2 "CANNY图"
#define WINDOWN_3 "效果图"

Mat srcImage, grayImage, out_Canny;
int min_Thresh = 50;
int max_Thresh = 250;

vector<vector<Point>> g_vContours;
vector<Vec4i> g_vHierarchy;

RNG G_RNG(1234);

void Find_Draw_COntours(int, void*)
{
    Canny(grayImage, out_Canny, min_Thresh, max_Thresh *2, 3);
    imshow(WINDOWN_2, out_Canny);
    
    findContours(out_Canny, g_vContours, g_vHierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
    Mat Drawing = Mat::zeros(out_Canny.size(), CV_8UC3);
    
    for(int i= 0;i <g_vContours.size(); i++)
    {
        Scalar color = Scalar(G_RNG.uniform(0, 255), G_RNG.uniform(0, 255), G_RNG.uniform(0, 255));
        drawContours(Drawing, g_vContours, i, color, 2, 8, g_vHierarchy, 0, Point());
    }
    imshow(WINDOWN_3, Drawing);
}

void DrawContours(){
    
    while (true) {
        VideoCapture cap(0);
        Mat srcImage;
        cap.read(srcImage);
        
        namedWindow(WINDOWN_1,WINDOW_AUTOSIZE);
        imshow(WINDOWN_1, srcImage);
        
        cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
        blur(grayImage, grayImage, Size(3, 3));
        
        createTrackbar("CANNY 值：", WINDOWN_1, &min_Thresh, max_Thresh, Find_Draw_COntours);
        Find_Draw_COntours(0, 0);
        char key = (char) waitKey(10);
        if(key == 27)
            break;

    }
    
}

void FeaturePointTwo(){

        Mat webcan;
        webcan = imread("/Users/fly/Documents/work/WorkSpace/CWorkSpace/OpencvDemo/Demo01/mz.jpg");
        namedWindow("dispaly img",WINDOW_AUTOSIZE);
        imshow("webcan", webcan);
        
        waitKey(0);
    
}



