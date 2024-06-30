//
// Created by MR on 2023/11/20.
//
#define N_MAX 35
#include <math.h>
#include "stdio.h"
int space[N_MAX]={0};
int ID[N_MAX]={0};
int count=1;
void push(int loc){//把loc后面的元素往后推一格
    for (int i = count; i > loc+1 ; --i) {
        space[i]=space[i-1];
        ID[i]=ID[i-1];
    }
}
void appoint(int id,int need){
    int key;
    for (int i = 0; i < count; ++i) {
        if(space[i]==need && ID[i]==0) {
            ID[i] = id;
            return;
        }
    }
    for (int i = 0; i < count; ++i) {
        if(space[i]>need && ID[i]==0){
            key=i;
            break;
        }
    }
    while (space[key]!=need)
    {
        space[key]--;
        push(key);
        count++;
        space[key+1]=space[key];
        ID[key+1]=0;
    }
    ID[key]=id;
}
void Q(void){
    printf("%d\n",count);
    for (int i = 0; i < count; ++i) {
        printf("%d ",ID[i]);
    }
    printf("\n");
}
int main(void)
{
    int n,q;
    scanf("%d%d",&n,&q);
    getchar();
    for (int i = 0; i < N_MAX; ++i) {
        space[i]=-1;
    }
    space[0]=n;
    while (q--)
    {
        char done;
        scanf("%c",&done);
        if(done=='Q'){
            Q();
        } else{
            int id;
            int req;
            scanf("%d",&id);
            scanf("%d",&req);
            int need;
            need= ceil(log2(req));
            appoint(id,need);
        }
        getchar();
    }
    return 0;
}