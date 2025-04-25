#include<stdio.h>

#define N 64

__global__ void gpu(int *a,int *b,int*c_gpu){
    int r=blockDim.x*blockIdx.x+threadIdx.x;
    int c=blockDim.y*blockIdx.y+threadIdx.y;

    if(r<N&&c<N){
        c_gpu[r*N+c]=a[r*N+c]+b[r*N+c];
    }
}

void cpu(int *a,int*b,int*c_cpu){
    for(int r=0;r<N;r++){
        for(int c=0;c<N;c++){
            c_cpu[r*N+c]=a[r*N+c]+b[r*N+c];
        }
    }
}

bool check(int *a,int *b,int*c_cpu,int*c_gpu){
    for(int r=0;r<N;r++){
        for(int c=0;c<N;c++){
            if(c_cpu[r*N+c]!=c_gpu[r*N+c])
            return false;
        }
    }
    return true;
}

int main(){
    int *a,*b,*c_cpu,*c_gpu;
    size_t size=N*N*sizeof(int);

    cudaMallocManaged(&a,size);
    cudaMallocManaged(&b,size);
    cudaMallocManaged(&c_cpu,size);
    cudaMallocManaged(&c_gpu,size);

    for(int r=0;r<N;r+=1){
        for(int c=0;c<N;c+=1){
            a[r*N+c]=r;
            b[r*N+c]=c;
            c_cpu[r*N+c]=0;
            c_gpu[r*N+c]=0;
        }
    }

   dim3 threads(16,16,1);
   dim3 blocks((N+threads.x-1)/threads.x,(N+threads.y-1)/threads.y,1);
   gpu<<<blocks,threads>>>(a,b,c_gpu);
   cudaDeviceSynchronize();

   cpu(a,b,c_cpu);
   check(a,b,c_cpu,c_gpu)?printf("ok"):printf("error");


    cudaFree(a);
    cudaFree(b);
    cudaFree(c_cpu);
    cudaFree(c_gpu);
}
