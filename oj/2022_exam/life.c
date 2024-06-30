//
// Created by MR on 2023/12/28.
//
#include <stdio.h>
#include <string.h>
#define MAX 1005
char cell[MAX];
void Infect(int loc,char tmp[]){
    if(tmp[loc]=='#' || tmp[loc]=='E')
        cell[loc]='A';
    else
        return;
}
void act(int len){
    char tmp[MAX]={0};
    strcpy(tmp,cell);
    for (int i = 1; i < len-1; ++i) {
       if(tmp[i]=='A' && tmp[i-1]=='I' && tmp[i+1]=='I')
           cell[i]='#';
    }
    for (int i = 0; i < len; ++i) {
        if(tmp[i]=='A'){
            if(i==0)
                Infect(i+1,tmp);
            else if(i==len-1)
                Infect(i-1,tmp);
            else {
                Infect(i-1,tmp);
                Infect(i+1,tmp);
            }
        }
    }
}
int main(void){
    int n;
    scanf("%d",&n);
    scanf("%s",cell);
    int len= strlen(cell);
    for (int i = 1; i <= n; ++i) {
        act(len);
    }
    printf("%s",cell);
    return 0;
}