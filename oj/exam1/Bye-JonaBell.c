//
// Created by Polaris on 2023/11/25.
//
#include "stdio.h"
#define N_MAX 1505
int main(void)
{
    int num_fox,death_num,gun,snail;
    scanf("%d%d%d%d",&num_fox,&death_num,&gun,&snail);
    int order[N_MAX]={0};
    int life[N_MAX];
    for (int i = 1; i <=num_fox ; ++i) {
        life[i]=snail;
    }
    int now_gun=gun;
    int now_live=num_fox;
    int count=1;
    for (int i = 1; i <=num_fox ; ++i) {
        if(life[i]>0) {
            order[i] = count;
            if (count == death_num) {
                if (now_gun > 0) {
                    life[i]--;
                    now_gun--;
                    if(life[i]==0)
                        now_live--;
                } else
                    now_gun = gun;
                count = 0;
            }
            count++;
        }
        if (i == num_fox)
            i = 0;
        if(now_live==1)
            break;
    }
    for (int i = 1; i <=num_fox ; ++i) {
        if(life[i]!=0){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
