//
// Created by MR on 2023/12/5.
//
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#define MAX 2050
void interleaveString(char *s1,char *s2,int ds1,int ds2,int size){
    char *ans= malloc(sizeof(char)*MAX);
    int len1= strlen(s1),len2= strlen(s2);
    int loc_s1=0;
    int loc_s2=0;
    int count_s1=0;
    int count_s2=0;
    int mode=1;
    for (int i = 0; i <size-1 ; ++i) {
        if(loc_s1==len1 && loc_s2==len2)
            break;
        if(loc_s1==len1)
            goto label;
        if(mode==1 || loc_s2==len2){
            ans[i]=s1[loc_s1];
            loc_s1++;
            count_s1++;
            if(count_s1==ds1) {
                mode = 2;
                count_s1 = 0;
            }
        } else if(mode==2){
            label:ans[i]=s2[loc_s2];
            loc_s2++;
            count_s2++;
            if(count_s2==ds2) {
                mode = 1;
                count_s2=0;
            }
        }

    }
    ans[len1+len2]='\0';
    ans[size-1]='\0';
    printf("%s\n",ans);
}
int main(void){
    int T;
    scanf("%d",&T);
    char *interval=";";
    while (T--){
        char str_enter[MAX];
        scanf("%s",str_enter);
        char *s1= strtok(str_enter,interval);
        char *s2= strtok(NULL,interval);
        char *d1= strtok(NULL,interval);
        char *d2= strtok(NULL,interval);
        char *tmp_size= strtok(NULL,interval);
       // printf("%s\n%s\n%s\n%s\n%s\n",s1,s2,d1,d2,size);
       int ds1=atoi(d1);
       int ds2= atoi(d2);
       int size= atoi(tmp_size);
        //printf("%d %d %d",ds1,ds2,size);
       interleaveString(s1,s2,ds1,ds2,size);
    }
    return 0;
}
