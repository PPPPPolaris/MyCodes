//
// Created by Polaris on 2023/11/18.
//
#include "stdio.h"
#define MAX 10005
void sort(int arrayA[],int arrayB[],int len)
{
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len-i-1; ++j) {
            if(arrayA[j]>arrayA[j+1]){
                int tmpA=arrayA[j];
                arrayA[j]=arrayA[j+1];
                arrayA[j+1]=tmpA;
                int tmpB=arrayB[j];
                arrayB[j]=arrayB[j+1];
                arrayB[j+1]=tmpB;
            }
        }
    }
    return;
}
int main(void)
{
    int type_wine,volume;
    int solo_value[MAX]={0};
    int max_add[MAX]={0};
    scanf("%d%d",&type_wine,&volume);
    for (int i = 0; i < type_wine; ++i) {
        scanf("%d",&solo_value[i]);
    }
    for (int i = 0; i < type_wine; ++i) {
        scanf("%d",&max_add[i]);
    }
    sort(solo_value,max_add,type_wine);
    int expensive=0;
    int volume_now=0;
    for (int i = type_wine-1; i >=0 ; --i) {
        if(volume_now<volume){
            if(max_add[i]<=volume-volume_now){
                expensive=expensive+solo_value[i] * max_add[i];
                volume_now+=max_add[i];
            } else {
                expensive += solo_value[i] * (volume - volume_now);
                volume_now = volume;
            }
        } else
            break;
    }
    printf("%d",expensive);
    return 0;
}
