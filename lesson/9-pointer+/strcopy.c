//
// Created by MR on 2023/11/21.
//
#include <stdio.h>
#include "string.h"
int main(void )
{
    char a[20];
    char *b="HELLO WORLD";
    strcpy(a,b);
    printf("%s",a);
    return 0;
}