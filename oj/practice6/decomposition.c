//
// Created by POlaris on 2023/11/25.
//
#include "stdio.h"
#define MAX 35
int ans[MAX];
void FindDecomposition(int n,int min,int nFound){
    if(n==0){
        for (int i = 0; i < nFound; ++i) {
            printf("%d ",ans[i]);
        }
        printf("\n");
    } else if(n<min)
        return;
    for (int i = min; i <=n ; ++i) {
        ans[nFound]=i;
        FindDecomposition(n-i,i,nFound+1);
    }
}
int main(void)
{
    int n;
    scanf("%d",&n);
    FindDecomposition(n,1,0);
    return 0;
}
