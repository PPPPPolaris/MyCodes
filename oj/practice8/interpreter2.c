//
// Created by MR on 2023/12/9.
//
#include "stdio.h"
#include "stdlib.h"
int main(void){
    int *X= malloc(sizeof (X));
    scanf("%x",X);
    printf("%d\n%u\n%f\n%.3e",*X,*X,*(float *)X,*(float *)X);
    return 0;
}