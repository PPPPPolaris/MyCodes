//
// Created by MR on 2023/10/10.
//
#include "stdio.h"
int main(void)
{
    int n;
    int a[100005];
    scanf("%d",&n);
    for (int i = 0; i < n+1; ++i) {
        scanf("%d",&a[i]);
    }
    int tuo=0,sum=a[0];
    for (int i = 1; i < n+1; i++) {

        if(i>sum && a[i]!=0) {
            tuo = tuo + i-sum;
            sum=i+a[i];
        }
        else {
            sum=sum+a[i];
        }
    }
    printf("%d",tuo);
    return 0;
}