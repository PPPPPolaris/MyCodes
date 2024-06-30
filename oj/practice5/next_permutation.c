//
// Created by Polaris on 2023/10/29.
//
#include "stdio.h"
int main(void)
{
    int n;
    int array[2000];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&array[i]);
    }
    //从后往前遍历，满足后面的比前面的小，确定m
    int m=1;
    for (int i = n-2; i >=0 ; --i) {
        if(array[i]>array[i+1])
            m++;
        else
            break;
    }
    /*另一种思路
     * int p=n;
     * while(array[p-1]>array[p]) p--;
     * p为最长递减后缀的第一个元素的位置
    */
    //printf("m:%d\n",m);
    //确定pk
    int pk=array[n-m-1],j=0,bigger[2000]={0};
    //printf("pk:%d\n",pk);
    //找到后缀中比pk大的所有数bigger
    for (int i = n-m; i <n ; ++i) {
        if(array[i]>pk){
            bigger[j]=array[i];
            j++;
        }
    }
    //确定bigger中最小的min
    int min=bigger[0];
    int loc_min=n-1;
    for (int i = 0; i < j; ++i) {
        if(bigger[i]<min) {
            min = bigger[i];
        }
    }
    //printf("min:%d\n",min);
    //在array中交换pk和min
    for (int i = 0; i < n; ++i) {
        if(array[i]==min) {
            int tmp = array[n - m - 1];
            array[n - m - 1] = array[i];
            array[i] = tmp;
            break;
        }
    }

    //翻转后m个数
    for (int i = 0; i < n-m; ++i) {
        printf("%d ",array[i]);
    }
    for (int i = n-1; i >=n-m ; --i) {
        printf("%d ",array[i]);
    }
    return 0;
}