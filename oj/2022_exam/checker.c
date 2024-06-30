//
// Created by MR on 2023/12/25.
//
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 200005
bool check(char in[],char out[],int len_in){
    int count[100]={0};
    int len_out= strlen(out);
    int index=0;
    char ans[MAX]={0};
    for (int i = 0; i < len_out; ++i) {
        ans[i]=out[len_out-1-i];
    }
    if(strcmp(ans,out) != 0)
        return false;
    for (int i = 0; i < len_in ; ++i) {
        if(in[i]!='?'){
            if(out[index]!=in[i])
                return false;
        } else{
            if(in[len_in-1-i]!='?')//only one '?'
            {
                if(out[index] != in[len_in-1-i])
                    return false;
            }else{//2 '?'
                if(!isdigit(out[index]) || !isdigit(out[index+1]))
                    return false;
                char tmp[3]={0};
                tmp[0]=out[index],tmp[1]=out[index+1];
                count[atoi(tmp)]++;
                if(count[atoi(tmp)]>2)
                    return false;
                index++;
            }
        }
        index++;
    }
    return true;
}
int main(void){
    int T;
    scanf("%d",&T);
    while (T--){
        int len;
        char in_str[MAX]={0};
        char out_str[MAX]={0};
        scanf("%d%s%s",&len,in_str,out_str);
        if(check(in_str,out_str,len))
            printf("Correct.\n");
        else
            printf("Wrong Answer!\n");
    }
    return 0;
}