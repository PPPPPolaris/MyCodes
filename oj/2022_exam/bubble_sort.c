//
// Created by MR on 2023/12/25.
//
#include "stdio.h"
#define MAX 50005
int main(void){
    int T;
    scanf("%d",&T);
    while (T--){
        int n;
        scanf("%d",&n);
        int arr[MAX]={0};
        int max=-2e9;
        for (int i = 0; i < n; ++i) {
            scanf("%d",&arr[i]);
            if(arr[i]>max)
                max=arr[i];
        }
        if(max==arr[n-1])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}