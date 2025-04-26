#include<stdio.h>

int main(){
    int id;
    cudaGetDevice(&id);

    cudaDeviceProp props;
    cudaGetDeviceProperties(&props,id);

    printf("device id: %d\n sms: %d\n capability major :%d\n capability minor :%d\n wrap size : %d\n",id,props.multiProcessorCount,props.major,props.minor,props.warpSize);

}
