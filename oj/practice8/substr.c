//
// Created by MR on 2023/11/27.
//
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stdio.h"
#define MAX 100005
char *S=NULL;
char *T=NULL;
bool judge(int loc_det_S,int len_T){
    for (int i = loc_det_S,j=0; i <loc_det_S+len_T ; ++i,++j) {
        if(*(S+i) != *(T+j))
            return false;
    }
    return true;
}
int main(){
    S= malloc(sizeof (char)*MAX);
    T= malloc(sizeof (char)*MAX);
    scanf("%s%s",S,T);
    int i= strlen(S),j= strlen(T);
    int *index;
    index= malloc(sizeof (int)*MAX);
    int count=0;
    for (int k = 0; k < i ; ++k) {
        if(*(S+k)==*T){
            if(judge(k,j)){
                *(index+count)=k;
                count++;
            }
        }
    }
    for (int k = 0; k < count; ++k) {
        printf("%d ",*(index+k));
    }
    return 0;
}
