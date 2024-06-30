//
// Created by MR on 2023/12/8.
//
#include "stdio.h"
#define MAX 10000
#define N_MAX 10
#include "string.h"
char stack[MAX];
int top=-1;
void push(char ch){
    top++;
    stack[top]=ch;
}
void pop(void){
    if(top==-1){
        printf("Empty\n");
    } else {
        stack[top] = '\0';
        top--;
    }
}
void Top(void){
    if(top==-1)
        printf("Empty\n");
    else
        printf("%c\n",stack[top]);
}
void print(void){
    if(top==-1)
        printf("Empty\n");
    else{
        for (int i = top; i >=0 ; --i) {
            printf("| %c |\n",stack[i]);
        }
        printf("|===|\n");
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    getchar();
    while (n--){
        char command[N_MAX]={0};
        gets(command);
        if(strcmp(command,"pop")==0)
            pop();
        else if(strcmp(command,"top")==0)
            Top();
        else if(command[1]=='u'){
            push(command[5]);
        } else
            print();
    }
    return 0;
}