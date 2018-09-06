////
////  SeamlessClone.cpp
////  Demo01
////
////  Created by Fly on 2017/11/21.
////  Copyright © 2017年 Fly. All rights reserved.
////
//
//
//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
//
//
//using namespace std;
//using namespace cv;
//
//
//// 边缘检测function
//// 输入单通道图像，输出标示边缘的黑白图像
//IplImage* doCanny(IplImage* image_input,double lowThresh,double highThresh,double aperture)
//{
//    
//    if(image_input->nChannels != 1)
//    {
//        return (0);
//    }
//    IplImage* image_output = cvCreateImage(cvGetSize(image_input),image_input->depth,image_input->nChannels);
//
//    cvCanny(image_input,image_output,lowThresh,highThresh,aperture);
//
//    return(image_output);
//}
//
//
////cameraframe 截图
//void ShowCapture01(){
//    
//    cvNamedWindow("Camera" , CV_WINDOW_AUTOSIZE );
//    
//    CvCapture* capture = cvCreateCameraCapture(CV_CAP_ANY);
//    
//    assert(capture != NULL);
//    
//    IplImage *frame = 0;
//    frame = cvQueryFrame(capture);
//
//    IplImage *frame_edge = cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,1);
//    
//    while(1)
//    {
//        frame = cvQueryFrame(capture);
//        
//        if(!frame)
//        {
//            break;
//        }
//        
//        //灰度处理
//        cvConvertImage(frame,frame_edge,0);
//        //边缘检测
//        frame_edge = doCanny(frame_edge,70,90,3);
//
//        cvShowImage("Camera",frame_edge);
//        
//        cvWaitKey(10);
//    }
//    
//    cvReleaseCapture(&capture);
//    cvReleaseImage( &frame_edge );
//    cvReleaseImage( &frame);
//}
//
////视频截图
//void ShowCapture02()
//{
//    while (true) {
//        VideoCapture cap(0);
//        Mat webcan;
//        cap.read(webcan);
//        
//        namedWindow("dispaly img",WINDOW_AUTOSIZE);
//        imshow("webcan", webcan);
//        waitKey(10);
//        
//    }
//}
//
//
//int main(int argc, char* argv[])
//{
//
//    ShowCapture01();
//    ShowCapture02();
//    return (int)0;
//}
//
//
