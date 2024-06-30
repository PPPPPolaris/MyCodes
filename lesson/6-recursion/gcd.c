//
// Created by Polaris on 2023/11/2.
//
#include "stdio.h"
int gcd1(int a,int b)
{
    if(a==b)
        return a;
    else if(a>b)
        return gcd1(a-b,b);
    else
        return gcd1(a,b-a);
}
int gcd2(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd2(b,a%b);
}
int main(void)
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("gcd1=%d\ngcd2=%d", gcd1(a,b), gcd2(a,b));
    return 0;
}