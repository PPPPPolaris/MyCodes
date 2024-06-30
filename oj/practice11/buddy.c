//
// Created by MR on 2023/12/30.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int sum=1;
struct node{
    int memory;
    int id;
    struct node *next;
};
struct linked_list{
    struct node *head;
    struct node *tail;
};
struct node *initNode(int n,struct node *nextNode){
    struct node *p= malloc(sizeof (struct node));
    p->memory=n;
    p->id=0;
    p->next=nextNode;
    return p;
}
void CreateList(struct linked_list *ll,struct node *firstNode){
    ll->head=firstNode;
    ll->tail=firstNode;
}
void divide(struct linked_list *ll,struct node *Node){
    struct node* nextNode=Node->next;
    Node->memory--;
    Node->next= initNode(Node->memory,nextNode);
    if(Node == ll->tail)
        ll->tail=Node->next;
    sum++;
}
void Q(struct linked_list *ll){
    printf("%d\n",sum);
    struct node *Node=ll->head;
    for (int i = 0; i < sum; ++i) {
        printf("%d ",Node->id);
        Node=Node->next;
    }
    printf("\n");
}
void A(struct linked_list *ll,int need,int Id){
    struct node* Node=ll->head;
    while (1) {
        Node=ll->head;
        for (int i = 0; i < sum; ++i) {
            if (Node->id == 0 && Node->memory == need) {
                Node->id = Id;
                return;
            }
            Node = Node->next;
        }
        Node = ll->head;
        for (int i = 0; i < sum; ++i) {
            if (Node->id == 0 && Node->memory > need) {
                divide(ll,Node);
                break;
            }
            Node=Node->next;
        }
    }
}
int main(void){
    int n,q;
    scanf("%d%d",&n,&q);
    struct linked_list list;
    CreateList(&list, initNode(n,NULL));
    while (q--){
        char ope[2];
        scanf("%s",ope);
        if(ope[0]=='Q'){
            Q(&list);
        } else{
            int id,m;
            scanf("%d%d",&id,&m);
            int need=ceil(log2(m));
            A(&list,need,id);
        }
    }
    return 0;
}