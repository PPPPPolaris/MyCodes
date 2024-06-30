//
// Created by MR on 2023/10/21.
//
#include "stdio.h"
int main(void)
{
    int A[5]={1,2,3,4,5};
    int B[5]={2,3,7,8,10};
    int result[10];
    int loc_a=0;
    int loc_b=0;
    int i=0;
    while (loc_a<=4 && loc_b<=4){
        if(A[loc_a]<=B[loc_b]){
            result[i]=tmpA[a];
            a++;
        } else{
            array[i]=tmpB[b];
            b++;
        }
        i++;
    }
    if(a<=mid){
        for (int j = a; j <=mid ; ++j) {
            array[i]=tmpA[j];
            i++;
        }
    }
    if(b<=right){
        for (int j = b; j <=right ; ++j) {
            array[i]=tmpB[j];
            i++;
        }
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d ",result[i]);
    }
    return 0;
}