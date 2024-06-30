//
// Created by MR on 2023/10/26.
//
#include "stdio.h"
int main(void)
{
    int n;
    char letter;
    int bucket[122]={0};
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; ++i) {
        scanf("%c",&letter);
        bucket[letter]++;
    }
    int count_letter=0;
    int max=bucket[0];
    for (int i = 0; i < 122; ++i) {
        if(bucket[i]!=0)
            count_letter++;
        if(bucket[i]>max)
            max=bucket[i];
    }
    char res[1000][100]={0};
    int seq=0;
    for (int i = 97; i <=122 ; ++i){
        if(bucket[i]!=0) {
            res[0][seq] = i;
            if(bucket[i-32]==0) {
                res[0][seq + 1] = ' ';
                seq = seq + 2;
            } else {
                res[0][seq + 1] = i - 32;
                res[0][seq+2]=' ';
                seq=seq+3;
            }

        } else{
            if(bucket[i-32]!=0)
            {
                res[0][seq] = i - 32;
                res[0][seq+1]=' ';
                seq=seq+2;
            }
        }
    }
    for (int j = 0; j <seq+1 ; ++j) {
        if(res[0][j]!=' '){
            for (int i = 2; i <max+2; ++i) {
                res[i][j]=' ';
                if(i<bucket[res[0][j]]+2) {
                    res[i][j] = '=';
                    res[1][j] = res[1][j - 1] = '-';
                }
            }
        } else{
            for (int i = 2; i <max+2 ; ++i) {
                res[i][j]=' ';
            }
        }
    }
    for (int i = max+1; i >=0; --i) {
        for (int j = 0; j < seq+1; ++j) {
            printf("%c",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}