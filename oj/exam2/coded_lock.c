//
// Created by MR on 2023/12/10.
//
#include "stdio.h"
#define MAX 1005
int W,N,D;
int move(int num,int tar){
    int tmp1=num;//front
    int tmp2=num;//back
    int count=0;
    while (tmp1!=tar && tmp2!=tar){
        tmp1=(tmp1+D)%N==0? N :(tmp1+D)%N;
        tmp2=((tmp2-D)%N)>0 ? (tmp2-D)%N : N+(tmp2-D)%N;
        count++;
        if(tmp1==num && tmp2==num && count==2)
            return 0;
    }
    return count;
}
int main(void){
    scanf("%d%d%d",&W,&N,&D);
    int num[MAX]={0};
    for (int i = 0; i < W; ++i) {
        scanf("%d",&num[i]);
    }
    int mid=W/2;
    int ans=0;
    for (int i = 0; i < mid; ++i) {
        if(num[i]==num[W-1-i])
            continue;
        else{
            if(move(num[i],num[W-1-i])==0) {
                printf("Impossible\n");
                goto label;
            } else
                ans+= move(num[i],num[W-i-1]);
        }
    }
    printf("%d\n",ans);
    label:return 0;
}