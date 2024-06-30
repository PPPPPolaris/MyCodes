//
// Created by MR on 2023/12/26.
//
#include <stdlib.h>
#include "stdio.h"
#include "limits.h"
#define MAX 40005
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main(void){
    int n1,n2;
    int num1[MAX]={0};
    int num2[MAX]={0};
    int max1=INT_MIN;
    int max2=INT_MIN;
    int loc1=0;
    int loc2=0;
    int tmp1[MAX]={0};
    int tmp2[MAX]={0};
    int j=0;
    scanf("%d",&n1);
    for (int i = 0; i < n1; ++i) {
        scanf("%d",&num1[i]);
        if(num1[i]>max1) {
            max1 = num1[i];
            tmp1[i]=num1[i];
            loc1=i;
        } else
            tmp2[j++]=num1[i];
    }
    scanf("%d",&n2);
    for (int i = 0; i < n2; ++i) {
        scanf("%d",&num2[i]);
        if(num2[i]>max2){
            max2=num2[i];
            tmp1[loc1+i+1]=num2[i];
            loc2=i;
        } else
            tmp2[j++]=num2[i];
    }
    qsort(tmp1,loc1+loc2+2,sizeof (int),cmp);
    qsort(tmp2,n1+n2-loc1-loc2-2,sizeof (int),cmp);
    for (int i = 0; i < loc1+loc2+2; ++i) {
        printf("%d ",tmp1[i]);
    }
    for (int i = n1+n2-loc1-loc2-3; i >=0 ; --i) {
        printf("%d ",tmp2[i]);
    }
    return 0;
}