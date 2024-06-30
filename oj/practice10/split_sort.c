//
// Created by MR on 2023/12/17.
//
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAX 1050
int cmp(const void *a,const void *b){
    char *str1=*(char **)a;
    char *str2=*(char **)b;
    return strcmp(str1,str2);
}
int main(void){
    char str[MAX]={0};
    scanf("%s",str);
    char *delim= malloc(sizeof (char));
    scanf("%s",delim);
    char *question= strchr(str,delim[0]);
    char *res[100]={NULL};
    int i=0;
    if(question==NULL) {
        printf("%s\n", str);
        goto label;
    }
    else{
        res[0]= strtok(str,delim);
        do {
            i++;
            res[i]= strtok(NULL,delim);
        } while (res[i]!=NULL);
    }
    qsort(res,i,sizeof (char *),cmp);
    for (int j = 0; j < i; ++j) {
        printf("%s\n",res[j]);
    }
    label:return 0;
}