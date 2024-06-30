//
// Created by MR on 2023/12/9.
//
#include <stdbool.h>
#include "stdio.h"
int Va,Vb,Vc;
int tarA,tarB,tarC;
void pour(int *src,int *des,int V_des){
    if((*src)+(*des)<=V_des){
        *des += *src;
        *src=0;
    } else{
        *des=V_des;
        *src=0;
    }
}
bool judge(int k,int *nowA,int* nowB,int *nowC){
    int tmpA=*nowA,tmpB=*nowB,tmpC=*nowC;
    if(*nowA==tarA && *nowB==tarB && *nowC==tarC)
        return true;
    else{
        if(k==0)
            return false;
        else {
            pour(nowA, nowB, Vb);
            bool ju1 = judge(k - 1, nowA, nowB, nowC);
            *nowA = tmpA, *nowB = tmpB, *nowC = tmpC;
            pour(nowA, nowC, Vc);
            bool ju2 = judge(k - 1, nowA, nowB, nowC);
            *nowA = tmpA, *nowB = tmpB, *nowC = tmpC;
            pour(nowB, nowA, Va);
            bool ju3 = judge(k - 1, nowA, nowB, nowC);
            *nowA = tmpA, *nowB = tmpB, *nowC = tmpC;
            pour(nowB, nowC, Vc);
            bool ju4 = judge(k - 1, nowA, nowB, nowC);
            *nowA = tmpA, *nowB = tmpB, *nowC = tmpC;
            pour(nowC, nowA, Va);
            bool ju5 = judge(k - 1, nowA, nowB, nowC);
            *nowA = tmpA, *nowB = tmpB, *nowC = tmpC;
            pour(nowC, nowB, Vb);
            bool ju6 = judge(k - 1, nowA, nowB, nowC);
            if (!ju1 && !ju2 && !ju3 && !ju4 && !ju5 && !ju6)
                return false;
            else
                return true;
        }
    }
}
int main(void){
    int k;
    scanf("%d",&k);
    int nowA,nowB,nowC;
    scanf("%d%d%d%d%d%d%d%d%d",&Va,&Vb,&Vc,&nowA,&nowB,&nowC,&tarA,&tarB,&tarC);
    if(judge(k,&nowA,&nowB,&nowC)){
        printf("Yes\n");
    } else
        printf("No\n");
    return 0;
}