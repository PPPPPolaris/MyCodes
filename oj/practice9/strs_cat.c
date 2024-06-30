//
// Created by MR on 2023/12/3.
//
#include <stdio.h>
#include "string.h"
#define STR_MAX 1005
void my_str_cat(char str1[],int loc,char str2[],int len2){
    for (int i = 0; i <len2 ; ++i) {
        str1[loc+i]=str2[i];
    }
}
int main(void){
    int T;
    scanf("%d",&T);
    while (T--) {
        char str1[STR_MAX]={0};
        char str2[STR_MAX]={0};
        scanf("%s%s", str1, str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int max_loc = len1;
        for (int i = 0; i < len1; ++i) {//遍历str1找到和str2【0】一i样的
            if (str1[i] == str2[0]) {
                int count = 0;
                for (int j = 0; j < len1 - i; ++j) {
                    if (str1[i + j] == str2[j])
                        count++;
                }
                if (count == len1 - i) {
                    max_loc = i;
                    break;
                }
            }
        }
        my_str_cat(str1,max_loc,str2,len2);
        printf("%s\n",str1);
    }
    return 0;
}
