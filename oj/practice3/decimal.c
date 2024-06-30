//
// Created by MR on 2023/10/18.
//
#include <math.h>
#include "stdio.h"
int main(void)
{
    int len,N;
    char array[31]={0};
    int flag=1;
    scanf("%d %d",&len,&N);
    getchar();
    for (int i = 0; i < len; ++i) {
        scanf("%c",&array[i]);
        if(N<=10) {
            if (array[i] > 47 + N)
                flag=0;
        } else{
            if(array[i]> 54 + N){
                flag=0;
            }
        }
    }
    int trans[31];
    int ten=0;
    if(flag==1){
        for (int i = 0; i < len; ++i) {
            if(48<=array[i] && array[i]<=57)
                trans[i]=array[i]-48;
            else
                trans[i]=array[i]-55;
            ten=ten+trans[i] * pow(N,len-1-i);
        }
        printf("%d",ten);
    } else{
        printf("Error");
    }
    return 0;
}