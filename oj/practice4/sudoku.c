//
// Created by Polaris on 2023/10/22.
//
#include <stdbool.h>
#include "stdio.h"
int main(void)
{
    int num[9][9];
    bool flag=true;
    //enter the numbers
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf("%d",&num[i][j]);
        }
    }
    //检查每一行
    for (int i = 0; i < 9; ++i) {
        int count_row[10]={0};
        for (int j = 0; j < 9; ++j) {
            for (int k = 1; k <=9; ++k) {
                if(num[i][j]==k){
                    count_row[k]++;
                }
            }
        }
        for (int k = 1; k <=9 ; ++k) {
            if(count_row[k]!=1)
                flag=false;
        }
    }//检查每一列
   for (int j = 0; j < 9; ++j) {
        int count_col[10]={0};
        for (int i = 0; i < 9; ++i) {
            for (int k = 1; k <=9 ; ++k) {
                if(num[i][j]==k)
                    count_col[k]++;
            }
        }
        for (int k = 1; k <=9 ; ++k) {
            if (count_col[k] != 1)
                flag = false;
        }
    }//检查每一宫
  for (int m = 0; m < 9; m=m+3) {
        for (int n = 0; n <9 ; n=n+3) {
            int count_matrix[10]={0};
            for (int i = m; i < m+3; i++) {
                for (int j = n; j <n+3 ; ++j) {
                    for (int k = 1; k <= 9; ++k) {
                        if(num[i][j]==k)
                            count_matrix[k]++;
                    }
                }
            }
            for (int k = 1; k <=9 ; ++k) {
                if(count_matrix[k]!=1)
                    flag=false;
            }
        }
    }
    if(flag==true)
        printf("YES");
    else
        printf("NO");
    return 0;
}