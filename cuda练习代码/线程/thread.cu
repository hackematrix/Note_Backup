#include<stdio.h>

void cpu(){
    for(int i=0;i<10;i++){
    printf("cpu\n");
    }
}

__global__ void gpu(){
  
    printf("hello gpu\n");
    
}

int main(){
    cpu();
    gpu<<<1,10>>>();
    cudaDeviceSynchronize();

}
