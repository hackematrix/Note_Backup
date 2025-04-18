#include<stdio.h>

__global__ void gpu(){
  
    printf("hello gpu\n");
    
}

int main(){
  gpu<<<1,1>>>();
  cudaDeviceSynchronize();
}
