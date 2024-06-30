//
// Created by Polaris on 2023/11/14.
//
#include <math.h>
#include "stdio.h"
int n,p;
double left,right;
int array[21];
double f(double x)
{
    double sum=0;
    for (int i = 0; i <= n; ++i) {
        sum = sum + array[i] * pow(x, i);
    }
    return pow(sum,p);
}
double simpson(double a,double b)
{
    double ans=((4.0 * f((a+b)/2)+ f(a)+ f(b))* (b-a))/6;
    return ans;
}
double adaptive_simpson(double left,double right,double error)
{
    double mid=(left+right)/2.0;
    double S = simpson(left, right);
    double SL= simpson(left,mid);
    double SR= simpson(mid,right);
    double integration=SL+SR+(SL+SR-S)/15.0;
    if(SL+SR-S<=15.0*error && SL+SR-S>=(-15.0)*error) {
        return integration;
    } else{
        return adaptive_simpson(left,mid,error/2)+adaptive_simpson(mid,right,error/2.0);
    }
}
int main(void)
{
    scanf("%d%d",&n,&p);
    for (int i = 0; i <=n ; ++i) {
        scanf("%d",&array[i]);
    }
    scanf("%lf%lf",&left,&right);
    double res= adaptive_simpson(left,right,0.0001);
    printf("%f",res);
    return 0;
}