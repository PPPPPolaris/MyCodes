//
// Created by MR on 2023/12/9.
//
#include <string.h>
#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#define MAX 5000
int main(void){
    char *s= malloc(sizeof (char)*MAX);
    while (scanf("%s",s)!=EOF){
        int len=strlen(s);
        printf("%c", toupper(*s));
        for (int i = 1; i <len ; ++i) {
            printf("%c", tolower(*(s+i)));
        }
        printf(" ");
    }
    free(s);
    return 0;
}