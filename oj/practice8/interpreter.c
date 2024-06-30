//
// Created by MR on 2023/11/27.
//
#include "stdio.h"
int main(void){
    int X;
    scanf("%x",&X);
    printf("%d\n%u\n",X,X);
    float *f=&X;
    printf("%f\n%.3e\n",*f,*f);

}