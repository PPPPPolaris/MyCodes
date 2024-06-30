//
// Created by Polaris on 2023/10/9.
//
#include "stdio.h"
int main(void)
{
    int n,a;
    int count[100000]={0};
    scanf("%d",&n);
    for (int i = 0; i <= (2 * n-2); ++i) {
        scanf("%d",&a);
        count[a]++;
    }
    for (int i = 0; i < 100000; ++i) {
        if(count[i]==1)
            printf("%d",i);
    }
    

}