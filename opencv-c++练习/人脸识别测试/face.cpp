#include"./face.hpp"

void test_face(){

    CascadeClassifier  faceCascade;
    // 错误处理
    if(!faceCascade.load("D:\\OpenCV\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_default.xml")){
        cout<<"无法加载分类器"<<endl;
    }

    Mat image=imread("face.jpeg");
    Mat grey;
    cvtColor(image,grey,COLOR_BGR2GRAY);

    vector<Rect> faces;
        faceCascade.detectMultiScale(grey, faces, 1.1, 3, 0, Size(80, 80));

        // 绘制检测结果
        for (const auto& face : faces) {
            rectangle(image, face, Scalar(0, 255, 0), 2);
        }

        // 显示结果
        imshow("Face Detection", image);
    
        waitKey(0);
        destroyAllWindows();
}