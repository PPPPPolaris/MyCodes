//
// Created by Polaris on 2023/10/14.
//
#include "stdio.h"
int main(void)
{
    int n;
    scanf("%d",&n);
    int a[n+5];
    for (int i = 1; i <=n ; ++i) {
        a[i]=0;
    }
    for (int j = 1; j <= n; ++j) {
        for (int m = 1; m <= n; ++m) {
            if(m%j == 0 && a[m] == 0){
                a[m]=1;
            } else if(m%j == 0 && a[m]== 1){
                a[m]=0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if(a[i]==1)
            printf("%d ",i);
    }
    return 0;
}