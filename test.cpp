#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc,char* argv[]){

	//--1.读入图片
	cv::Mat image = cv::imread("horse_hw.jpg");

	//--2.转换灰度图
	cv::Mat gray;
	cv::cvtColor(image,gray,CV_RGB2GRAY);
	
	//--3.二值化灰度图
	cv::Mat dst;
	cv::threshold(gray,dst,45,255,cv::THRESH_BINARY_INV);
	
	//--4.draw the rectangle
	rectangle(image,cv::Rect(20,20,150,50),cvScalar(200,100,50));
	
	//--5.draw the text string
	putText(image,"MarsHu",cv::Point(25,60),CV_FONT_HERSHEY_COMPLEX,1,cv::Scalar(255,0,0));
	//--4.显示结果(原图和结果图显示在一起)
	const int width  = image.cols;
	const int height = image.rows;
	cv::Mat show_image(cv::Size(width,2*height),CV_8UC3);
	//将image拷贝到显示图片指定位置
	image.copyTo(show_image(cv::Rect(0,0,width,height)));
	//将dst转换为3通道，使得show_image和dst通道数一致，或者使用convertTo()函数做操作
	cv::cvtColor(dst,dst,CV_GRAY2RGB);
	//将dst拷贝image指定位置
	dst.copyTo(show_image(cv::Rect(0,height,width,height)));
	//显示
	cv::imshow("show",show_image);
	cv::waitKey(0);
}
