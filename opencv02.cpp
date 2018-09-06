////
////  opencv02.cpp
////  Demo01
////
////  Created by Fly on 2017/11/27.
////  Copyright © 2017年 Fly. All rights reserved.
////
//#include <opencv2/calib3d/calib3d.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/opencv.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <stdio.h>
//
//using namespace cv;
//
//int main(){
//    Mat picture(800,800,CV_8UC3,cvScalarAll(0));
//    namedWindow("draw",WINDOW_AUTOSIZE);
//    
//    Mat b;
//    picture.copyTo(b);
//    //绘制
//    //画箭头
//    Point point1 = Point(0, 0);
//    Point point2 = Point(100, 100);  // 2表示线宽  8 表示线型  0 移动小数位数  0.1表示箭头的长度
//    arrowedLine(picture, point1, point2, Scalar(170, 170, 170), 2,8,0,0.1);
//    //线性：8 or 4 or CA_VV
//    
//    //画直线
//    point1 = Point(150,150);
//    point2 = Point(300,300);
//    line(picture, point1, point2, cvScalarAll(250));
//    
//    //画圆
//    int r = 350;//半径
//    Point center = Point(400, 400);  //其中2改为-1 表示填充
//    circle(picture, center, r, Scalar(200, 200, 200), 2,8,0);
//    
//    //画矩形
//    Rect rec(300,300,150,150);
//    rectangle(picture, rec, Scalar(255, 255, 255), 2, 8, 0);
//    
//    //clipLine的作用是剪切图像矩形区域内部的直线
//    point1 = Point(100, 250);
//    point2 = Point(450, 450);
//    line(picture, point1, point2, Scalar(0, 255, 0), 2, 8, 0);
//    clipLine(rec, point1, point2);
//    line(picture, point1, point2, Scalar(0, 0, 255), 2, 8, 0);
//    
//    //输入文字
//    Point textPt(210, 50);
//    String text = "drawtext";
//    int fontFace = FONT_HERSHEY_PLAIN;
//    double fontScale = 2;
//    int thickness = 2;
//    putText(picture, text, textPt, fontFace, fontScale, Scalar(0, 111, 255), thickness);
//    //getTextSize()返回一个指定字体以及大小的String所占的空间
//    int baseline = 0;
//    Size textSize = getTextSize(text, fontFace,fontScale, thickness, &baseline);
//    rectangle(picture, Point(textPt.x, textPt.y - textSize.height), Point(textPt.x + textSize.width, textPt.y + thickness/2), Scalar(255, 255, 255), 2, 8, 0);
//    
//    //画标记
//    //目前支持六种标记
//    //MARKER_TILTED_CROSS,MARKER_STAR, MARKER_DIAMOND, MARKER_SQUARE ,MARKER_TRIANGLE_UP, MARKER_TRIANGLE_DOWN
//    drawMarker(picture, Point(480, 50), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
//    drawMarker(picture, Point(480, 70), Scalar(0, 0, 255), MARKER_STAR);
//    drawMarker(picture, Point(480, 90), Scalar(0, 0, 255), MARKER_DIAMOND);
//    drawMarker(picture, Point(480, 110), Scalar(0, 0, 255), MARKER_SQUARE);
//    drawMarker(picture, Point(480, 130), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
//    drawMarker(picture, Point(480, 150), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);
//    
//    //画椭圆
//    Size 轴(20, 50);//轴线长度，横着20，竖着50
//    ellipse(picture, Point(50, 150), 轴, 20.0, 0.0, 300.0, Scalar(55, 123, 222), -1);
//    //参数说明，axes表示轴，20.0表示整个椭圆旋转20度，从0开始画到300度
//    //重载函数利用了RotatedRect,表示在一个旋转矩形里画最大椭圆
//    RotatedRect box1(Point(320, 500), Size(40, 100), -20);//负的为逆时针
//    ellipse(picture, box1, Scalar(255, 0, 0),2);
//    
//    //画多边形
//    Point points[2][20];
//    points[0][0] = Point(300, 100);
//    points[0][1] = Point(400, 100);
//    points[0][2] = Point(450, 200);
//    points[0][3] = Point(350, 250);
//    points[0][4] = Point(250, 200);
//    
//    points[1][0] = Point(300, 100) + Point(-200, +150);
//    points[1][1] = Point(400, 100) + Point(-200, +150);
//    points[1][2] = Point(450, 200) + Point(-200, +150);
//    points[1][3] = Point(350, 250) + Point(-200, +150);
//    points[1][4] = Point(250, 200) + Point(-200, +150);
//    const Point* pt[2] = { points[0], points[1] };
//    int npt[2] = { 5,5 };
//    polylines(picture, pt, npt, 2, 1, Scalar(0, 0, 255), 3);
//    fillPoly(picture, pt, npt, 1, Scalar(250, 255, 0), 8);
//
//    //绘制半透明矩形
////    DrawTransRec(picture, 50, 320, 400, 100, Scalar(255, 122, 122), 0.2);
//    
//    
//    imshow("draw", picture);
//    waitKey(0);
//    return 0;
//}
