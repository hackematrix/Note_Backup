#include<iostream>
#include<cmath>
#include<Eigen/Core>
#include<Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    Vector3d p(2.0,1.0,1.0);
    Matrix3d matrix1;
    Matrix3d matrix2;
    auto b=2.0;
    auto c=sqrt(b)/2;    //根号2
    //旋转45度
    matrix1<< c, -c, 0.0, c, c, 0.0, 0.0, 0.0, 1.0;
    //平移
    matrix2<<1.0,0.0,1.0,0.0,1.0,2.0,0.0,0.0,1.0;
    
    Matrix3d matrix3;
    matrix3=matrix2*matrix1;

    Vector3d answer;
    answer=matrix3*p;

    cout<<"给定一个点 P=(2,1), 将该点绕原点先逆时针旋转 45◦,再平移 (1,2)的结果"<<answer<<endl;

    return 0;

}
