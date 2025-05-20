#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int main(){
    cv::Mat image=cv::imread("D:\\piture\\output.png");

    if(image.empty()){
        cout<<"无法打开图片"<<endl;
        return -1;
    }
    
    /*图片信息 */
    int width=image.cols;//图片宽度
    int height=image.rows;//图片高度
    int channels=image.channels(); //图片通道数

    cout<<"图片宽度"<<width<<endl;
    cout<<"图片高度"<<height<<endl;
    cout<<"图片通道数"<<channels<<endl;

    /*图片保存*/
    bool isSave=cv::imwrite("output.png",image);
    if(isSave){
        cout<<"保存成功"<<endl;
    }
    else{
        cout<<"保存失败"<<endl;
    }


    /*打开图片 */
    cv::imshow("Display Image",image);

    cv::waitKey(0);

    return 0;
}
