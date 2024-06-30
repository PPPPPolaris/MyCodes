//
// Created by MR on 2023/11/19.
//
#include <stdbool.h>
#include "stdio.h"
#define MAX 10000
char contents[MAX]={0};
int loc=0;
bool is_empty(void)
{
    return loc==0;
}
void push(char m)
{
    contents[loc++] = m;
}
void pop(void){
    if(loc==0)
        printf("Empty\n");
    else
        contents[--loc]=0;
}
void top(void){
    if(is_empty())
        printf("Empty\n");
    else
        printf("%c\n",contents[loc-1]);
}
void print(void)
{
    if(is_empty())
        printf("Empty\n");
    else{
        for (int i = loc-1; i >=0 ; --i) {
            printf("| %c |\n",contents[i]);
        }
        printf("|===|\n");
    }
}
int main(void)
{
    int n;
    scanf("%d",&n);
    getchar();
    while (n--){
        char done[10]={0};
        gets(done);
        //scanf("%s",done);
        if(done[0]=='p'&& done[1]=='o')
            pop();
        else if(done[0]=='t')
            top();
        else if(done[3]=='h')
            push(done[5]);
        else
            print();
    }
    return 0;
}