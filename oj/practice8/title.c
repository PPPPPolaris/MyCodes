//
// Created by MR on 2023/11/27.
//
#include <string.h>
#include <ctype.h>
#include "stdio.h"
#include "stdlib.h"
#define MAX 4100
int main(void){
    char *title;
    char *res;
    title=malloc(sizeof(char)*MAX);
    res= malloc(sizeof(char)*MAX);
    gets(title);
    int len= strlen(title);
    strcpy(res,title);
    *res=toupper(*title);
    for (int i = 1; i <len ; ++i) {
        *(res+i)= tolower(*(title+i));
    }
    for (int i = 0; i < len; ++i) {
        if(*(res+i)==' '){
            *(res+i+1)= toupper(*(title+i+1));
        }
    }
    printf("%s",res);
    return 0;
}