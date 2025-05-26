#include "./star.hpp"

void print_star(){
    auto f=[](int i,int j){
        return i>=j;
    };

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<(f(i,j)?"*":" ");
        }
        cout<<endl;
    }
}