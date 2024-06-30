//
// Created by MR on 2023/12/1.
//
#include "stdio.h"
//#include "string.h"
int strcmp(const char* str_1,const char* str_2){
    while (*str_1==*str_2 && *str_1!=0 && *str_2 !=0){
        str_1++;
        str_2++;
    }
    if(*str_1==0 && *str_2==0)
        return 0;
    return (*str_1>*str_2)?1:-1;//避免无符号数做减法带来的风险
}
int main(void){
    char *str_1="hello";
    char *str_2="world";
    printf("%d", strcmp(str_2,str_1));
    return 0;
}