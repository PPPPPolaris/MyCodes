//
// Created by MR on 2023/10/22.
//
#include "stdio.h"
int main(void)
{
    int m;
    int n;
    scanf("%d %d",&m,&n);
    char row[1000][2005]={0};
    getchar();
    for (int j = 0; j < n; ++j) {
        scanf("%c",&row[0][j]);
    }
    for (int i = 1; i <m ; ++i) {
        for (int j = 0; j < n; ++j)
        {
            if(j==0 && row[i-1][j]=='1'){//01x
               row[i][j]='1';
            } else if(j==0 && row[i-1][j]=='0'){//00x
                row[i][j]=row[i-1][j+1];//考虑最左边的情况
            }
            else if(j==n-1)//xx0
                row[i][j]=row[i-1][j];//最右边的情况
            else {
                if (row[i - 1][j] == '1' && row[i - 1][j - 1] == '1') {//11x
                    if (row[i - 1][j + 1] == '1')//111
                        row[i][j] = '0';
                    else//110
                        row[i][j] = '1';
                } else if (row[i - 1][j] == '1' && row[i - 1][j - 1] == '0') {//01x
                    row[i][j] = '1';
                } else //00x,10x
                    row[i][j] = row[i - 1][j + 1];

            }
           // printf("%c", row[i][j]);
        }
        printf("%s\n",row[i]);
    }
    return 0;
}