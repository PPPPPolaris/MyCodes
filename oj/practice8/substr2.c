//
// Created by MR on 2023/12/9.
//
#include <string.h>
#include "stdlib.h"
#include "stdio.h"
#define MAX 100005
int main(void){
    char *S= malloc(sizeof (char)*MAX);
    char *T= malloc(sizeof (char)*MAX);
    scanf("%s%s",S,T);
    int lenS=strlen(S);
    int lenT= strlen(T);
    for (int i = 0; i < lenS; ++i) {
        if(*(S+i)==*T){
            for (int j = 0; j < lenT; ++j) {
                if(*(S+i+j)!=*(T+j))
                    break;
                if(j==lenT-1)
                    printf("%d ",i);
            }
        }
    }
    free(S);
    free(T);
    return 0;
}