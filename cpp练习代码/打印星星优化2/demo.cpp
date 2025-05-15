#include "demo.h"

bool check(int i,int j){
    return j<=i;
}

void print(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<(check(i,j)?"*":" ");
        }
        cout<<endl;
    }
}