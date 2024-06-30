//
// Created by MR on 2023/10/22.
//
#include "stdio.h"
int main(void)
{
    int n;
    scanf("%d",&n);
    getchar();
    char map[101][101]={0};
    int count[100][100]={0};
    int vectors[8][2]={{0,1},{0,-1},{1,0},{-1,0},
            {-1,1},{-1,-1,},{1,-1},{1,1}};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%c",&map[i][j]);
        }
        getchar();
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(map[i][j]=='o'){
                for (int k = 0; k < 8; ++k) {
                    int newI = i + vectors[k][0];
                    int newJ = j + vectors[k][1];
                    if (newI>=0 && newI < n && newJ>=0 && newJ<n && map[newI][newJ] == '*')
                        count[i][j]++;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == '*')
                printf("*");
            else
                printf("%d",count[i][j]);
        }
        printf("\n");
    }

    return 0;
}