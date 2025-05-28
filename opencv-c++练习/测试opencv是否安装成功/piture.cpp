#include"./piture.hpp"

void gauss(){
    Mat image=imread("img1.png");
    
    // 错误处理
    if(image.empty()){
        cout<<"无法打开图片"<<endl;
    }

    // 图片缩小
    Mat ResizeImage;
    resize(image,ResizeImage,Size(800,800));

    // 高斯滤波
    Mat gaussImage;
    GaussianBlur(ResizeImage,gaussImage,Size(15,15),0);

    // 显示图片
    imshow("Original image",ResizeImage);
    imshow("Gauss Image",gaussImage);

    waitKey(0);
    destroyAllWindows();
}