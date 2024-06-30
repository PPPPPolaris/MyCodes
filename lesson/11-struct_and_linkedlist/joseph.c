//
// Created by MR on 2023/12/12.
//
#include "stdio.h"
#include "stdlib.h"
struct node{
    int data;
    struct node *next;
};
struct linklist{
    struct node* begin;
    struct node* end;
};
void init_list(struct linklist *ll){
    ll->begin=NULL;
    ll->end=NULL;
}
void append(struct linklist *ll,struct node *new_node){
    if(ll->begin==NULL && ll->end==NULL){
        ll->begin=new_node;
        ll->end=new_node;
        new_node->next=ll->begin;
    } else{
        ll->end->next=new_node;
        ll->end=new_node;
        ll->end->next=ll->begin;
    }
}
struct node* init_node(int value){
    struct node* p= malloc(sizeof (struct node));
    p->data=value;
    p->next=NULL;
    return p;
}
void sit_circle(int num,struct linklist *ll){
    for (int i = 1; i <=num ; ++i) {
        append(ll, init_node(i));
    }
}
void to_kill(struct linklist *ll,int kill_num){
    struct node *p=ll->begin;
    struct node *pre_p;
    while (p->next != p){
        int count=1;
        do {
            pre_p=p;
            p=p->next;
            count++;
        } while (count < kill_num);
        //delete p
        pre_p->next=p->next;
        printf("No.%d is killed\n",p->data);
        free(p);
        p=pre_p->next;
    }
    ll->begin=p;
}
void get_survivor(struct linklist *ll){
    printf("Only No.%d survives\n",ll->begin->data);
}
void display(struct linklist *ll){
    struct node *p=ll->begin;
    while (p!=ll->end){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}
int main(void){
    int all,kill_num;
    scanf("%d%d",&all,&kill_num);
    struct linklist list;
    init_list(&list);
    sit_circle(all,&list);
    //display(&list);
    to_kill(&list,kill_num);
    get_survivor(&list);
    free(list.begin);
    return 0;
}