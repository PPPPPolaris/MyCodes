//
// Created by MR on 2023/12/7.
//
#include "stdio.h"
#define MAX 10000
int main(void){
    int n,m,t;
    scanf("%d%d%d",&n,&m,&t);
    int a[MAX]={0};
    int b[MAX]={0};
    int min=2e9;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int j = 0; j < m; ++j) {
        scanf("%d",&b[j]);
        int left=0,right=n-1;
        while (left<=right){
            int mid=(left+right)/2;
            if(a[mid]<=t-b[j]){
                if(t-a[mid]-b[j]<min)
                    min=t-a[mid]-b[j];
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
    }
    if(min==2e9)
        printf("-1");
    else
        printf("%d",min);
    return 0;
}