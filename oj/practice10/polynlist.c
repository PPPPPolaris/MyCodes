//
// Created by MR on 2023/12/17.
//
#include <stdbool.h>
#include "stdio.h"
#include "math.h"
#define MAX 15
#define NUM_MAX 20005
int p1,p2;
char name[MAX]={0};
int max(int a,int b){
    return a>b?a:b;
}
void Print_single(int res,int h_num,bool is_No1){
    if(res==0)
        return;
    if(!is_No1){
        if(res>0)
            printf("+");
        else
            printf("-");
    } else{
        if(res<0)
            printf("-");
    }
    if(res!=1 && res != -1)
       printf("%d",abs(res));
    if(h_num==0) {
        if(abs(res)==1)
            printf("1");
        else
            return;
    }
    else{
        printf("%s",name);
        if(h_num!=1)
            printf("^%d",h_num);
    }
}
void plus(int const num1[],int const num2[]){
    int res_plus[NUM_MAX]={0};
    for (int i = 0; i <= max(p1,p2) ; ++i) {
        res_plus[i]=num1[i]+num2[i];
    }
    bool have_fir=true;
    Print_single(res_plus[max(p1,p2)], max(p1,p2),1);
    if(res_plus[max(p1,p2)]==0)
        have_fir=false;
    int is_No1[NUM_MAX]={0};
    if(max(p1,p2)>=1) {
        for (int i = max(p1, p2) - 1; i >= 0; --i) {
            if(!have_fir && res_plus[i]!=0){
                have_fir=true;
                is_No1[i]=1;
            }
            Print_single(res_plus[i], i, is_No1[i]);
        }
    }
    printf("\n");
}
void minus(int const num1[],int const num2[]){
    int res_minus[NUM_MAX]={0};
    for (int i = max(p1,p2); i >=0 ; --i) {
        res_minus[i]=num1[i]-num2[i];
    }
    bool have_fir=true;
    Print_single(res_minus[max(p1,p2)], max(p1,p2),1);
    if(res_minus[max(p1,p2)]==0)
        have_fir=false;
    int is_No1[NUM_MAX]={0};
    if(max(p1,p2)>=1){
        for (int i = max(p1,p2)-1; i >=0 ; --i) {
            if(!have_fir && res_minus[i]!=0){
                have_fir=true;
                is_No1[i]=1;
            }
            Print_single(res_minus[i],i,is_No1[i]);
        }
    }
    printf("\n");
}
void multiply(int const num1[],int  const num2[]){
    int res_mul[NUM_MAX]={0};
    for (int i = 0; i <= p1 ; ++i) {
        for (int j = 0; j <=p2 ; ++j) {
            res_mul[i + j]+=num1[i] * num2[j];
        }
    }
    bool have_fir=true;
    Print_single(res_mul[p1 + p2],p1 + p2,1);
    if(res_mul[max(p1,p2)]==0)
        have_fir=false;
    int is_No1[NUM_MAX]={0};
    if(p1 + p2 >=1){
        for (int i = p1 + p2 -1; i >=0 ; --i) {
            if(!have_fir && res_mul[i]!=0){
                have_fir=true;
                is_No1[i]=1;
            }
            Print_single(res_mul[i],i,is_No1[i]);
        }
    }
    printf("\n");
}
int main(void){
    scanf("%d%d",&p1,&p2);
    scanf("%s",name);
    int num1[NUM_MAX]={0};
    int num2[NUM_MAX]={0};
    for (int i = p1; i >= 0; --i)
        scanf("%d",&num1[i]);
    for (int i = p2; i >=0; --i)
        scanf("%d",&num2[i]);
    plus(num1,num2);
    minus(num1,num2);
    multiply(num1,num2);
    return 0;
}