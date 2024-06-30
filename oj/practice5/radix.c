//
// Created by Polaris on 2023/10/28.
//
#include "stdio.h"
void trans(int num,char str[3])//把整数转化为字符串，低位存在前
{
    int i=0;
    do {
        str[i]=num%10+'0';
        num/=10;
        i++;
    } while (num>0);
}
int newX(char X[3],int i)//把作为i进制数的X转化为十进制数
{
    if(X[1]==0)
        return X[0]-'0';
    else
        return (X[1]-'0')*i+X[0]-'0';
}
int main(void)
{
    int p,q,r;
    scanf("%d %d %d",&p,&q,&r);
    char P[3]={0},Q[3]={0},R[3]={0};
    trans(p,P);
    trans(q,Q);
    trans(r,R);
    for (int i = 2; i <=40 ; ++i) {
         if(P[0]>=i+'0'|| P[1]>=i+'0'||Q[0]>=i+'0'||Q[1]>=i+'0'||R[0]>=i+'0'||R[1]>=i+'0')
             continue;//如果当前提供的进制不合法则continue，如6不可能为2进制数
         int newP= newX(P,i);
         int newQ= newX(Q,i);
         int newR= newX(R,i);
         if(newP*newQ==newR)
         {
             printf("%d",i);
             break;
         } else if(newP * newQ != newR && i==40)
             printf("0\n");
    }
    return 0;
}