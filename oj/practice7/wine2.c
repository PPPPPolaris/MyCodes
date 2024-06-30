//
// Created by MR on 2023/12/8.
//
#include "stdio.h"
#define MAX 10000
int type,vol;
void SpecialBubbleSort(int arrA[],int arrB[]){
    for (int i = 0; i < type; ++i) {
        for (int j = 0; j < type-i-1; ++j) {
            if(arrA[j]>arrA[j+1]){
                int tmp1=arrA[j];
                arrA[j]=arrA[j+1];
                arrA[j+1]=tmp1;
                int tmp2=arrB[j];
                arrB[j]=arrB[j+1];
                arrB[j+1]=tmp2;
            }
        }
    }
}
int main(void){

    scanf("%d%d",&type,&vol);
    int value[MAX]={0};
    int max_add[MAX]={0};
    for (int i = 0; i < type; ++i) {
        scanf("%d",&value[i]);
    }
    for (int i = 0; i < type; ++i) {
        scanf("%d",&max_add[i]);
    }
    SpecialBubbleSort(value,max_add);
    int L=0,bill=0;
    int index=type-1;
    while (L<vol){
        if(max_add[index]<=vol-L){
            L+=max_add[index];
            bill+=value[index] * max_add[index];
            index--;
        } else{
            bill+=value[index] * (vol-L);
            L=vol;
        }
    }
    printf("%d",bill);
    return 0;
}