#include"./hello.hpp"

void print_heart(){

  //判断在心形内
  auto f=[](int a,int b){
    double x=((b*2)/15.0-3)/2;
    double y=(a*2)/15.0-2;
    
    return pow(pow(x,2)+pow(y,2)-1,3)+pow(x,2)*pow(y,3)<0;
  };

  for(int i=5;i<25;i++){
   for(int j=0;j<50;j++){
     std::cout<<(f(i,j)?"*":" ");
   } 
   std::cout<<std::endl;
  }
}
