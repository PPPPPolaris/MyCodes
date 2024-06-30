//
// Created by MR on 2023/12/29.
//
#include <stdio.h>
#include <stdbool.h>
#define N_MAX 1005
void move(int num[],int index){
    if(index==1)
        return;
    else{
        int tmp=num[index];
        for (int i = index-1; i >=1 ; --i) {
            num[i+1]=num[i];
        }
        num[1]=tmp;
    }
}
int main(void){
    int T;
    scanf("%d",&T);
    while (T--){
        int n;
        int m;
        scanf("%d%d",&n,&m);
        int num[N_MAX]={0};
        int ope[N_MAX]={0};
        for (int i = 1; i <= n ; ++i) {
            scanf("%d",&num[i]);
        }
        for (int i = 1; i <= m ; ++i) {
            scanf("%d",&ope[i]);
            move(num,ope[i]);
        }
        bool sorted=true;
        for (int i = 1; i <n ; ++i) {
            if(num[i]>num[i+1]){
                sorted=false;
                break;
            }
        }
        if(sorted)
            printf("I love C programming language\n");
        else
            printf("mayi is a good teacher\n");
    }
    return 0;
}