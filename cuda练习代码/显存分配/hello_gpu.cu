#include<stdio.h>
#include<stdlib.h>

void cpu(int *a,int N){
    for(int i=0;i<N;i++){
        a[i]=i;
    }
}

__global__ void gpu(int *a,int N){
    int i=blockIdx.x*blockDim.x+threadIdx.x;
    if(i<N){
        a[i]*=2;
    }
}

bool check(int *a,int N){
    for(int i=0;i<N;i++){
        if(a[i]!=2*i)
        return false;
    }
    return true;
}

int main(){
    const int N=1000;
    size_t size=N*sizeof(int);

    int *a;
    cudaMallocManaged(&a,size);

    // 运行cpu
    cpu(a,N);

    //运行gpu
    size_t threads=256;
    size_t blocks=(N+threads-1)/threads;
    gpu<<<blocks,threads>>>(a,N);
    cudaDeviceSynchronize();

    //运行check函数
    check(a,N)?printf("OK"):printf("Error");
    cudaDeviceSynchronize();
}
