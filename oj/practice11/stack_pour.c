//
// Created by MR on 2023/12/29.
//
#include <stdio.h>
#include <stdlib.h>
struct stack{
    int *content;
    int top;
    struct stack *next;
};
struct stack *pStack[1000];
struct linked_list{
    struct stack *head;
    struct stack *tail;
};
void CreateList(struct linked_list *ll){
    ll->head=NULL;
    ll->tail=NULL;
}
void append(struct linked_list *ll,struct stack *NewStack){
    if(ll->head==NULL && ll->tail==NULL){
        ll->head=NewStack;
        ll->tail=NewStack;
    } else{
        ll->tail->next=NewStack;
        ll->tail=NewStack;
        ll->tail->next=NULL;
    }
}
struct stack* CreateStack(int num){
    struct stack *p= malloc(sizeof (struct stack));
    p->content= malloc(sizeof (int));
    p->content[0]=num;
    p->top=0;
    pStack[num]=p;
    return p;
}
void Stacks(struct linked_list *ll,int num){
    for (int i = 1; i <= num ; ++i) {
        append(ll, CreateStack(i));
    }
}
void pour(int x,int y){
    struct stack *X_stack=pStack[x];
    struct stack *Y_stack=pStack[y];
    Y_stack->content= realloc(Y_stack->content,sizeof (int )*(X_stack->top+1 + Y_stack->top+1));
    for (int i = X_stack->top; i >= 0; --i) {
        Y_stack->content[++(Y_stack->top)]=X_stack->content[i];
        X_stack->content[i]=0;
        X_stack->top--;
    }
}
void display(struct linked_list *ll,int num){
    struct stack *Stack=ll->head;
    for (int i = 1; i <= num ; ++i) {
        if(Stack->top ==-1)
            printf("0");
        else {
            for (int j = 0; j <= Stack->top; ++j) {
                printf("%d ", Stack->content[j]);
            }
        }
        printf("\n");
        Stack=Stack->next;
    }
}
int main(void){
    int n;
    int m;
    scanf("%d%d",&n,&m);
    struct linked_list list;
    CreateList(&list);
    Stacks(&list,n);
    while (m--){
        int x,y;
        scanf("%d%d",&x,&y);
        pour(x,y);
    }
    display(&list,n);
    return 0;
}