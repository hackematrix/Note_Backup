#include<iostream>
using namespace std;

int main(int argc,char *argv[]){
    // 匿名函数
    auto f=[](int i,int j){
        return j<=i;  
    };

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<(f(i,j)?"*":" ");
        }
        cout<<endl;
    }

    return 0;
}
