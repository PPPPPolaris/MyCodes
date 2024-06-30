//
// Created by MR on 2024/1/2.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 2000005
int count;
struct node{
    char c;
    struct node* pre;
    struct node* next;
    struct node* last_same;
};
struct linkedList{
    struct node* head;
    struct node* tail;
    struct node* lastLow;
    struct node* lastUp;
};
void CreateLinkedList(struct linkedList* ll){
    ll->head=NULL;
    ll->tail=NULL;
    ll->lastLow=NULL;
    ll->lastUp=NULL;
}
struct node* CreateNode(char letter){
    count++;
    struct node* NewNode= malloc(sizeof (struct node));
    NewNode->c=letter;
    return NewNode;
}
void append(struct linkedList* ll,struct node* NewNode,bool isLower){
    if(ll->head == NULL && ll->tail == NULL){
        ll->head=NewNode;
        ll->tail=NewNode;
        if(isLower)
            ll->lastLow=NewNode;
        else
            ll->lastUp=NewNode;
    } else{
        ll->tail->next=NewNode;
        NewNode->pre=ll->tail;
        ll->tail=NewNode;
        ll->tail->next=NULL;
        if(isLower) {
            NewNode->last_same=ll->lastLow;
            ll->lastLow=NewNode;
        }
        else {
            NewNode->last_same=ll->lastUp;
            ll->lastUp = NewNode;
        }
    }
}
void write(struct linkedList* ll,char letter,bool isLower){
    append(ll, CreateNode(letter),isLower);
}
void ReversePrint(int len,char str[]){
    for (int i = len-1; i >=0 ; --i) {
        printf("%c",str[i]);
    }
}
void Query(int len,struct linkedList* ll){
    if(len < count/2) {
        struct node* pNode=ll->tail;
        char *message= calloc(len, sizeof(char));
        for (int i = 0; i < len; ++i) {
            message[i] = pNode->c;
            pNode = pNode->pre;
        }
        ReversePrint(len,message);
    } else{
        struct node* pNode=ll->head;
        for (int i = 0; i < count; ++i) {
            if(i >= count-len)
                printf("%c",pNode->c);
            pNode=pNode->next;
        }
    }
    printf("\n");
}
void delete(struct linkedList* ll,char type){
    if(type == 'm'){
        struct node* target=ll->lastLow;
        if(target == NULL)
            return;
        else{
            count--;
            if(target != ll->head)
                target->pre->next=target->next;
            else
                ll->head=target->next;
            if(target != ll->tail)
                target->next->pre=target->pre;
            else
                ll->tail=target->pre;
            ll->lastLow=target->last_same;
        }
    } else{
        struct node* target=ll->lastUp;
        if(target == NULL)
            return;
        else{
            count--;
            if(target != ll->head)
                target->pre->next=target->next;
            else
                ll->head=target->next;
            if(target != ll->tail)
                target->next->pre=target->pre;
            else
                ll->tail=target->pre;
            ll->lastUp=target->last_same;
        }
    }
}
int main(void){
    int Q;
    scanf("%d",&Q);
    struct linkedList list;
    CreateLinkedList(&list);
    while (Q--){
        char *ope= malloc(sizeof(char) * MAX);
        scanf("%s",ope);
        if(ope[0]=='?'){
            realloc(ope, sizeof(char));
            int k;
            scanf("%d",&k);
            Query(k,&list);
        } else{
            int len= strlen(ope);
            realloc(ope,sizeof(char) * len);
            for (int i = 0; i < len; ++i) {
                if(ope[i] != 'm' && ope[i] != 'M'){
                    write(&list,ope[i], islower(ope[i]));
                } else{
                    delete(&list,ope[i]);
                }
            }
        }
        free(ope);
    }
    return 0;
}