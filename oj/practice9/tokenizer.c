//
// Created by MR on 2023/12/6.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
#define LEN 16
char *res[MAX]={NULL};
int count=0;
bool is_error=false;
char *reserved[LEN]={"const","int","float","double","long",
                     "static","void","char","extern","return",
                     "break","enum","struct","typedef","union","goto"};
char *operator[11]={"+","-","*","/","=","==","!=",">=","<=",">","<"};
bool is_reserved(char *str){
    for (int i = 0; i < 16; ++i) {
        if(strcmp(str,reserved[i])==0)
            return true;
    }
    return false;
}
bool is_integer(char *str){
    int len=strlen(str);
    if(len>1 && str[0]=='0')
        return false;
    for (int i = 0; i < len; ++i) {
        if(isdigit(str[i])==0)
            return false;
    }
    return true;
}
bool is_float(char *str){
    int len= strlen(str);
    int count_dot=0;
    if(len==1)
        return false;
    else{
        for (int i = 0; i < len; ++i) {
            if(str[i]=='.')
                count_dot++;
        }
        if (count_dot==1)
            return true;
        else
            return false;
    }
}
bool is_operator(char *str){
    for (int i = 0; i < 11; ++i) {
        if(strcmp(str,operator[i])==0)
            return true;
    }
    return false;
}
bool is_variable(char *str){
    if(isdigit(str[0])!=0 || is_reserved(str))//是数字
        return false;
    int len= strlen(str);
    for (int i = 0; i < len; ++i) {
        if (str[i]!='_' && isalpha(str[i])==0)
            return false;
    }
    return true;
}
void process(char *str){
    if (str==NULL || str[0]=='\0')
        return;
    if(!is_reserved(str) && !is_integer(str) && !is_float(str) && !is_operator(str) && !is_variable(str)) {
        is_error=true;
    }
    else if(is_variable(str)){
        res[count]="variable ";
        count++;
    } else if(is_operator(str)){
        res[count]="operator ";
        count++;
    } else if(is_float(str)){
        res[count]="float ";
        count++;
    } else if(is_integer(str)){
        res[count]="integer ";
        count++;
    }else if(is_reserved(str)){
        res[count]="reserved ";
        count++;
    }
    return;
}
void clear(char str[]){
    for (int i = 0; i < MAX; ++i) {
        str[i]=0;
    }
    return;
}
int main(void){
    char str[MAX]={0};
    while (scanf("%s",str)!=EOF){
        char *position= strchr(str,';');
        if(position == NULL){
            process(str);
        }else{
           int len= strlen(str);
           char tmp[MAX]={0};
           int index=0;
            for (int i = 0; i < len; ++i) {
                if (str[i]==';') {
                    process(tmp);
                    clear(tmp);
                    index=0;
                    res[count] = "\n";
                    count++;
                } else{
                    tmp[index]=str[i];
                    index++;
                }
            }
            process(tmp);
        }
        clear(str);
    }
    if (is_error){
        printf("Compile Error\n");
    } else{
        for (int i = 0; i < count; ++i) {
            printf("%s",res[i]);
        }
    }
    return 0;
}