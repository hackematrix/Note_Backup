#include<iostream>
#include<string>
using namespace std;

int main(int argc,char*argv[]){
    // argc 命令行参数的个数
    // argv 命令行参数列表
    string num1,num2;

    cout<<"Enter the number 1:";
    cin>>num1;
    cout<<"Enter the number 2:";
    cin>>num2;

    int number1=stoi(num1);
    int number2=stoi(num2);

    cout<<number1<<"+"<<number2<<"="<<number1+number2<<endl;

    printf("%d+%d=%d",number1,number2,number1+number2);

    return 0;
}
