//
// Created by MR on 2023/10/10.
//
#include "stdio.h"
int main(void)
{
    int n,k;
    char a[1000005],c;
    scanf("%d",&n);
    scanf("%c",&c);
    for (int i = 0; i < n+1; ++i) {
        scanf("%c",&a[i]);
    }
    scanf("%d",&k);
    int mid=k;
    for (int low = 0; low < k-1 ; low++,k--) {
        int tmp1=a[low];
        a[low]=a[k-1];
        a[k-1]=tmp1;
    }
    for (int k=mid; k<n ; k++,n--) {
        int tmp2=a[k];
        a[k]=a[n-1];
        a[n-1]=tmp2;
    }
    printf("%s",a);
    return 0;
}