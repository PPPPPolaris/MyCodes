//
// Created by MR on 2023/11/28.
//
#include "stdio.h"
int main(void){
    struct Number{
        enum {INT_TYPE,DOUBLE_TYPE}kind;
        union {
            int i;
            double d;
        }num;
    }p;
    p.num.i=9;
    printf("%d",p.num.i);
}