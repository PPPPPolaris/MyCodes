//
// Created by MR on 2023/10/15.
//
#include "stdio.h"
int main(void)
{
    int n,k;
    scanf("%d %d",&n,&k);
    int live[10005]={0};
    for (int i = 1; i <=n ; ++i) {
        live[i]=1;
    }
    int danger=0;
    int num_of_live=n;
    for (int i = 1; i <= n; i++) {
        danger = danger + live[i];
        if (num_of_live == 1) {
            break;
        } if (danger == k) {
            live[i] = 0;
            danger = 0;
            num_of_live = num_of_live - 1;
        }  if (i == n) {
            i = 0;
        }
    }
    for (int i = 1; i <=n ; ++i) {
        if(live[i]==1)
       printf("%d",i);
    }
    return 0;
}