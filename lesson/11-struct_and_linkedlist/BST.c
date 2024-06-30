//
// Created by MR on 2023/12/12.
//
#include "stdio.h"
#include "stdlib.h"
struct Bnode{
    char data;
    struct Bnode *left;
    struct Bnode *right;
};
void insert_B_tree(struct Bnode **pBnode,char ch){//*pBnode==root
    printf("%c\n",ch);
    if(*pBnode==NULL) {
        *pBnode=malloc(sizeof (struct Bnode));
        (*pBnode)->data = ch;
        (*pBnode)->left=NULL;
        (*pBnode)->right=NULL;
    }
    else{
        if(ch <(*pBnode)->data) {
            printf("To left\n");
            insert_B_tree(&((*pBnode)->left), ch);
        }
        else {
            printf("To right\n");
            insert_B_tree(&((*pBnode)->right), ch);
        }
    }
}
void in_order_display(struct Bnode *root){
    if(root!=NULL) {
        in_order_display(root->left);
        printf("%c", root->data);
        in_order_display(root->right);
    }
}
void freeBST(struct Bnode *root){
    if(root !=NULL){
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}
int main(void){
    char arr[]="BHJDFY";
    struct Bnode *root=NULL;
    int i=0;
    while (arr[i]!='\0'){
        insert_B_tree(&root,arr[i]);
        i++;
    }
    in_order_display(root);
    return 0;
}