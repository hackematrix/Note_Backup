#include<stdio.h>
#include<stdlib.h>

void cpu(int *a,int N){
    for(int i=0;i<N;i++){
        a[i]=i;
    }
}

__global__ void gpu(int *a,int N){
    int threadi=blockIdx.x*blockDim.x+threadIdx.x;
    int stride=gridDim.x*blockDim.x;
    for(int i=threadi;i<N;i+=stride){
        a[i]*=2;
    }
}

bool check(int *a,int N){
    for(int i=0;i<N;i++){
        if(a[i]!=2*i){
            
        return false;
        }
    }
    return true;
}

int main(){
    const int N=1000;
    size_t size=N*sizeof(int);

    int *a;
    cudaError_t error;
    error=cudaMallocManaged(&a,size);
    if(error!=cudaSuccess){
        printf("Error:%s\n",cudaGetErrorString(error));
    }

    // 运行cpu
    cpu(a,N);

    //运行gpu
    size_t threads=256;
    size_t blocks=1;
    gpu<<<blocks,-1>>>(a,N);

    error=cudaGetLastError();
    if(error!=cudaSuccess){
        printf("Error:%s\n",cudaGetErrorString(error));
    }

    cudaDeviceSynchronize();

    //运行check函数
    check(a,N)?printf("OK"):printf("Error");
    cudaFree(a);
}
