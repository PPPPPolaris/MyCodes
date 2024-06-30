//
// Created by MR on 2023/10/19.
//
#include "stdio.h"
int main(void)
{
    int n;
    scanf("%d",&n);
    getchar();
    char array[100005]={0};
    for (int i = 0; i < n; ++i) {
        scanf("%c",&array[i]);
    }
    char num[105][3]={0};
    for (int i = 0; i < 100; ++i) {
        num[i][0]=48+i/10;
        num[i][1]=48+i%10;
    }
    int count=0;
   for (int i = 0; i <n; ++i)
    {
        if(array[i]=='?'&& array[n-1-i]!='?') {
            printf("%c", array[n-1-i]);
        } else if(array[i]!='?'){
            printf("%c",array[i]);
        }else if(array[i]=='?'&& array[n-1-i]=='?'){
            if(i<=(n/2-1)) {
                printf("%s", num[count]);
                count=count+1;
            }
            else{
                printf("%c%c",num[count-1][1],num[count-1][0]);
                count=count-1;
            }
        }
    }

    return 0;
}