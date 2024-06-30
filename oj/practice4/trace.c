//
// Created by MR on 2023/10/23.
//
#include <stdbool.h>
#include "stdio.h"
int main(void)
{
    int n,m,x,y;
    scanf("%d %d %d %d",&n,&m,&x,&y);
    getchar();
    char map[50][50]={0};
    int ans=0;
    bool vis[50][50]={false};
    int vectors[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%c",&map[i][j]);
            if(map[i][j]=='#') {
                ans = ans + 1;
            }
        }
        getchar();
    }
    printf("%d\n%d %d\n",ans,x,y);
    vis[x-1][y-1]=true;
    int count=1;
    int newI;
    int newJ;
    for (int i = x-1,j=y-1; count<ans; i=newI,j=newJ) {
        for (int k = 0; k < 4; ++k) {
                newI=i+vectors[k][0];
                newJ=j+vectors[k][1];
                if(map[newI][newJ]=='#' && vis[newI][newJ]==false){
                    vis[newI][newJ]=true;
                    printf("%d %d\n",newI+1,newJ+1);
                    count++;
                    break;
                }
        }

    }
    return 0;
}