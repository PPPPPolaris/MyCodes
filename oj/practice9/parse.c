//
// Created by MR on 2023/12/5.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define RULE_MAX 150
#define COM_MAX 105//本地测不了太大的
char rule[RULE_MAX]={0};
void PrintPointerArray(char arr[][COM_MAX],int len){
    for (int i = 1; i < len; ++i) {
        printf("%s\n",arr[i]);
    }
    return;
}
bool is_solo(char command){
    int len_rule=strlen(rule);
    for (int i = 0; i < len_rule; ++i) {
        if(command==rule[i]){
            if(i==len_rule-1)
                return true;
            else if(rule[i+1]!=':')
                return true;
        }
    }
    return false;
}
bool need_num(char command){
    int len_rule= strlen(rule);
    for (int i = 0; i < len_rule; ++i) {
        if(command==rule[i] && i!=len_rule-1 && rule[i+1]==':')
            return true;
    }
    return false;
}
int main(void){
    char name[COM_MAX]={0};
    scanf("%s%s",rule,name);
    char command[COM_MAX]={0};
    char tmp_res[COM_MAX][COM_MAX]={0};
    char res[COM_MAX][COM_MAX]={0};
    // res[0]=name;
    int count=1;
    int i=0;
    int flag=0;
    while (scanf("%s",command)!=EOF){
        //printf("%s",command);
        if(i!=0 && need_num(tmp_res[i-1][0])){
            flag=0;
            res[count-1][1]='=';
            for (int j = 0; j < strlen(command); ++j) {
                res[count-1][2+j]=command[j];
            }
            i++;
            continue;
        }
        if(command[0]=='-'){
            if(!is_solo(command[1]) && !need_num(command[1])) {
                printf("%s:invalid option -- '%c'", name, command[1]);
                goto label;
            } else if(is_solo(command[1])){
                res[count][0]=command[1];
                count++;
            } else if(need_num(command[1])){
                res[count][0]=command[1];
                tmp_res[i][0]=command[1];
                count++;
                flag=1;
            }
        }
        i++;
    }
    if(flag==1) {
        printf("%s:option requires an argument -- '%c'", name, res[count-1][0]);
        goto label;
    }
    printf("%s\n",name);
    PrintPointerArray(res,count);
    label:return 0;
}