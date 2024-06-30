//
// Created by MR on 2023/10/14.
//
#include "stdio.h"
int main(void )
{
    int n;
    scanf("%d",&n);
    char a[2005],c;
    scanf("%c",&c);
    for (int i = 0; i < n; ++i) {
        scanf("%c",&a[i]);
    }
    for (int j = 0; j < n; ++j) {
        if(a[j] =='?')
            printf("%c",a[n-1-j]);
        else
            printf("%c",a[j]);
    }
    return 0;
}