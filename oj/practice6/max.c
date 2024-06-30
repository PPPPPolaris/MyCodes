//
// Created by MR on 2023/11/13.
//
#include "stdio.h"
#define MAX 100000
int ans[MAX][2]={0};
void maxseg(int left,int right,int array[MAX])
{
    int max = array[0];
    int loc_max = 0;
    for (int i = left; i <= right; ++i) {
        if (array[i] > max) {
            max = array[i];
            loc_max = i;
        }
    }
    ans[loc_max][0]=left;
    ans[loc_max][1]=right;
    if(left>=right)
    {
        return;
    } else {
        maxseg(left, loc_max - 1, array);
        maxseg(loc_max + 1, right, array);
    }
}
int main(void)
{
    int n;
    int array[MAX]={0};
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&array[i]);
    }
    maxseg(1,n,array);
    for (int i = 1; i <=n ; ++i) {
        printf("%d %d",ans[i][0],ans[i][1]);
        printf("\n");
    }
    return 0;
}