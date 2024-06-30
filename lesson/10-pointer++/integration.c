//
// Created by MR on 2023/12/5.
//
#include "stdio.h"
#include "math.h"
#define SPLIT_NUM 1000000
double Integration(double left,double right,double (*fun)(double)){
    double interval=(right-left)/SPLIT_NUM;
    double sum=0.0;
    for (int i = 0; i <SPLIT_NUM ; ++i) {
        double xi=left+interval * i;
        double yi=fun(xi);
        sum+=yi * interval;
    }
    return sum;
}
int main(void){
    double left;
    double right;
    printf("Enter the left and the right:\n");
    scanf("%lf%lf",&left,&right);
    printf("Integrate sinx from x=%.2f to x=%.2f is about %f\n",left,right, Integration(left,right,sin));
    printf("Integrate cosx from x=%.2f to x=%.2f is about %f\n",left,right, Integration(left,right,cos));
    return 0;
}