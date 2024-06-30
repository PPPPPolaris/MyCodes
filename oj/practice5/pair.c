//
// Created by Polaris on 2023/10/30.
//
#include "stdio.h"
int main(void)
{
    int n,m,t;
    int a[1000]={0};
    int b[1000]={0};
    scanf("%d %d %d",&n,&m,&t);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    int min=2e9;
    for (int j = 0; j < m; ++j) {
        scanf("%d",&b[j]);
        int low=0,high=n-1;
        while (low<=high) {
            int mid = (low + high) / 2;
            if (t>=a[mid]+b[j]) {
                if(t-a[mid]-b[j]<min)
                   min = t - a[mid] - b[j];
                low = mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    if(min==2e9)
        printf("-1");
    else
        printf("%d",min);
    return 0;
}