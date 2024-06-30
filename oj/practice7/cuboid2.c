//
// Created by MR on 2023/12/8.
//
#include <string.h>
#include <assert.h>
#include "stdio.h"
#define MAX 1005
void swap(int *x,int *y){
    int tmp=*x;
    *x=*y;
    *y=tmp;
}
int main(void){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    char ope[MAX]={0};
    scanf("%s",ope);
    int len=strlen(ope);
    int x=0,y=0;
    for (int i = 0; i < len; ++i) {
        char ch=ope[i];
        switch (ch) {
            case 'W':x-=c;swap(&a,&c);
                break;
            case 'A':y-=c;swap(&b,&c);
                break;
            case 'S':x+=a;swap(&a,&c);
                break;
            case 'D':y+=b;swap(&b,&c);
                break;
            default:assert(0);
        }
    }
    printf("%d %d %d %d\n",x,x+a,y,y+b);
    return 0;
}