//
// Created by Polaris on 2023/12/30.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
struct stack{
    int *content;
    int top;
};
void CreateStack(struct stack Stack[],int num){
    for (int i = 1; i <=num ; ++i) {
        Stack[i].top=0;
        Stack[i].content= malloc(sizeof (int));
        Stack[i].content[Stack[i].top]=i;
    }
}
void pour(struct stack Stack[],int x,int y){
    int X_top=Stack[x].top;
    Stack[y].content= realloc(Stack[y].content,sizeof(int) * (X_top+1+Stack[y].top+1));
    for (int i = X_top; i >=0 ; --i) {
        Stack[y].content[Stack[y].top+1]=Stack[x].content[i];
        Stack[y].top++;
        Stack[x].content[i]=0;
        Stack[x].top--;
    }
}
void display(struct stack Stack[],int num){
    for (int i = 1; i <= num ; ++i) {
        int Top=Stack[i].top;
        if(Top==-1)
            printf("0");
        else {
            for (int j = 0; j <= Top; ++j) {
                printf("%d ", Stack[i].content[j]);
            }
        }
        printf("\n");
    }
}
int main(void){
    int n;
    int m;
    scanf("%d%d",&n,&m);
    struct stack *Stacks=malloc(sizeof (struct stack) * (n+5));
    CreateStack(Stacks,n);
    while (m--){
        int x,y;
        scanf("%d%d",&x,&y);
        pour(Stacks,x,y);
    }
    display(Stacks,n);
    return 0;
}