//
// Created by MR on 2023/10/9.
//
#include "stdio.h"
int fun(int m)
{
    long long int j=1;
    for (int i = 1; i<=m; ++i) {
        j=(j * i)%10007;
    }
    return j%10007;
}
int main(void)
{
    int n;
    long long sum=0;
    scanf("%d",&n);
    for (int i = 1; i <=n; ++i) {
        sum=sum+fun(i)%10007;
    }
    printf("%lld", sum%10007);
    return 0;
}