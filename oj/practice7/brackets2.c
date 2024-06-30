//
// Created by MR on 2023/12/8.
//
#include "stdio.h"
#include "string.h"
#define MAX 100005
char stack[MAX];
int top=-1;
void clear(void){
    int len= strlen(stack);
    for (int i = 0; i < len; ++i) {
        stack[i]='\0';
    }
    top=-1;
}
int main(void){
    int T;
    scanf("%d",&T);
    while (T--){
        char brackets[MAX]={0};
        scanf("%s",brackets);
        int len= strlen(brackets);
        for (int i = 0; i < len; ++i) {
            if(brackets[i]=='('|| brackets[i]=='[' || brackets[i]=='{'){
                top++;
                stack[top]=brackets[i];
            }else{
                if(top==-1){
                    printf("False\n");
                    goto label;
                }
                if((brackets[i]==')' && stack[top]=='(') || (brackets[i]==']' && stack[top]=='[') || (brackets[i]=='}' && stack[top]=='{'))
                {
                    stack[top]='\0';
                    top--;
                }
            }
        }
        printf(top==-1?"True\n":"False\n");
        label:clear();
    }
    return 0;
}