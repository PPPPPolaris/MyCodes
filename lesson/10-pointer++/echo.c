//
// Created by MR on 2023/12/4.
//
#include "stdio.h"
int main(int argc,char *argv[]){
    printf("%d",argc);
    int i=1;
    while (i!=1){
        printf("%s %c",argv[i]+i,*(argv[i]+1));
        i++;
    }
}