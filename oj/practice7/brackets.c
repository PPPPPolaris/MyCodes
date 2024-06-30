//
// Created by MR on 2023/11/19.
//
#include <stdbool.h>
#include <string.h>
#include "stdio.h"
#define MAX 100000
char stack[MAX]={0};
int top=0;
void clear(char stack[])
{
    for (int i = 0; i < MAX; ++i) {
        stack[i]=0;
    }
}
void push(char m)
{
    stack[top]=m;
    top++;
}
void pop(void)
{
    top--;
    stack[top]=0;
}
int main(void)
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        char brackets[MAX]={0};
        scanf("%s",brackets);
        bool is_valid=true;
        int len=strlen(brackets);
        for (int i = 0; i < len; ++i) {
            if(brackets[i]=='('||brackets[i]=='['||brackets[i]=='{')
                push(brackets[i]);
            else{
                if(brackets[i]==stack[top-1]+1||brackets[i]==stack[top-1]+2)
                pop();
            }
        }
        if(top!=0)
            is_valid=false;
        if(is_valid)
            printf("True\n");
        else
            printf("False\n");
        clear(stack);
        top=0;
    }
    return 0;
}