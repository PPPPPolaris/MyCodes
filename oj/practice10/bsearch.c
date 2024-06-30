//
// Created by MR on 2023/12/16.
//
#include "stdio.h"
#include "stdlib.h"
#define MAX 1000//to be changed
int cmp(const void *a,const void *b){
    return (*(int *)a - *(int *)b);
}
int main(void){
    int n,q;
    scanf("%d%d",&n,&q);
    int arr[MAX]={0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    while (q--){
        int key;
        scanf("%d",&key);
        int *res= bsearch(&key,arr,n,sizeof (int),cmp);
        if(res)
            printf("%d\n",res-arr);
        else
            printf("-1\n");
    }
    return 0;
}