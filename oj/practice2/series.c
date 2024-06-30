//
// Created by MR on 2023/10/9.
//
#include "stdio.h"
#include "math.h"
int main(void)
{
    int n;
    float x;
    scanf("%f %d",&x,&n);
    int i=0;
    float sum=0;
    while (i<=n)
    {
        sum=sum+ (pow(-1.0,i) * pow(x,2 * i+1))/(2 * i+1);
        i++;
    }
    printf("%.10f",4 * sum);
    return 0;
}