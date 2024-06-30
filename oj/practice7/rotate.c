//
// Created by MR on 2023/11/21.
//
#include <string.h>
#include "stdio.h"
#define MAX 1005
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void rotate(char opr[],int left,int right,int *px1,int *px2,int *py1,int *py2,int *x,int *y,int *z)
{
    if(left==right){
        if(opr[left]=='S'){
            *px1=*px2;
            *px2+=*z;
            swap(x,z);
        } else if(opr[left]=='W'){
            *px2=*px1;
            *px1-=*z;
            swap(x,z);
        } else if(opr[left]=='A'){
            *py2=*py1;
            *py1-=*z;
            swap(y,z);
        } else{
            *py1=*py2;
            *py2+=*z;
            swap(y,z);
        }
        return;
    } else{
        rotate(opr,left,right-1,px1,px2,py1,py2,x,y,z);
        rotate(opr,right,right,px1,px2,py1,py2,x,y,z);
    }
}
int main(void)
{
    int a;
    int b;
    int c;
    scanf("%d%d%d",&a,&b,&c);
    char opr[MAX]={0};
    scanf("%s",opr);
    int x1=0,x2=a,y1=0,y2=b;
    int len=strlen(opr);
    rotate(opr,0,len-1,&x1,&x2,&y1,&y2,&a,&b,&c);
    printf("%d %d %d %d",x1,x2,y1,y2);
    return 0;
}