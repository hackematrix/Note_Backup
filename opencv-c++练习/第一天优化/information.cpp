#include"./infomation.hpp"

void piture_information(){
    Mat image=imread("ina.png");

    // 错误处理
    if(image.empty()){
        cout<<"错误无法打开图片"<<endl;
    } 
    
    //显示图片
    imshow("Display Image",image);

    //等待按键
    waitKey(0);

    //图片信息
    auto width=image.cols;//图片的宽度
    auto height=image.rows;//图片的高度
    auto channels=image.channels(); //图片的通道

    cout<<"图片的宽度: "<<width<<endl;
    cout<<"图片的高度: "<<height<<endl;
    cout<<"图片的通道: "<<channels<<endl;

    //关闭图片
    destroyAllWindows();
}