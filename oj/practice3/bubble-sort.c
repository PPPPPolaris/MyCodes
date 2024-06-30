//
// Created by MR on 2023/10/17.
//
#include "stdio.h"
int main(void) {
    int T;
    int result[10005]={0};
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int n;
        int a[50005] = {0};
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[j]);
        }
        int max=a[0];
        for (int j = 1; j < n; ++j) {
            if(a[j]>max)
                max=a[j];
        }
        if (max==a[n-1])
            result[i] = 1;
        else
            result[i]=0;
    }
    for (int i = 0; i < T; ++i) {
        if (result[i] == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}