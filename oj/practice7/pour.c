//
// Created by Polaris on 2023/11/22.
//
#include <stdbool.h>
#include "stdio.h"
int Va,Vb,Vc;
int a0,b0,c0;
void pour(int *source,int *destination,int V_destination){
    if(*source<=V_destination-*destination) {
        *destination += *source;
        *source=0;
    }else{
        *destination=V_destination;
        *source=0;
    }
}
bool judge_pour(int k,int *a,int *b,int *c){
    int tmp_a=*a;
    int tmp_b=*b;
    int tmp_c=*c;
    if(*a==a0 && *b==b0 && *c==c0)
        return true;
    else{
        if(k==0)
            return false;
        else{
            pour(a,b,Vb);
            bool jud1=judge_pour(k-1,a,b,c);
            *a=tmp_a;
            *b=tmp_b;
            *c=tmp_c;
            pour(a,c,Vc);
            bool jud2= judge_pour(k-1,a,b,c);
            *a=tmp_a;
            *b=tmp_b;
            *c=tmp_c;
            pour(b,a,Va);
            bool jud3= judge_pour(k-1,a,b,c);
            *a=tmp_a;
            *b=tmp_b;
            *c=tmp_c;
            pour(b,c,Vc);
            bool jud4= judge_pour(k-1,a,b,c);
            *a=tmp_a;
            *b=tmp_b;
            *c=tmp_c;
            pour(c,a,Va);
            bool jud5= judge_pour(k-1,a,b,c);
            *a=tmp_a;
            *b=tmp_b;
            *c=tmp_c;
            pour(c,b,Vb);
            bool jud6= judge_pour(k-1,a,b,c);
            if(!jud1 && !jud2 && !jud3 && !jud4 && !jud5 && !jud6)
                return false;
            else
                return true;
        }
    }
}
int main(void)
{
    int k,a,b,c;
    scanf("%d%d%d%d%d%d%d%d%d%d",&k,&Va,&Vb,&Vc,&a,&b,&c,&a0,&b0,&c0);
    if(judge_pour(k,&a,&b,&c))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}