//
// Created by Polaris on 2023/11/17.
//
#include <math.h>
#include "stdio.h"
#define MAX 2045
char map[MAX][MAX];
void paint(int n,int x,int y)
{
    if(n==1) {
        map[y][x-2] = '/';
        map[y][x-1]='\\';
        map[y-1][x-3]='/';
        map[y-1][x-2]=map[y-1][x-1]='_';
        map[y-1][x]='\\';
        return;
    } else{
        paint(n-1,x- pow(2,n-2)*4,y- pow(2,n-1));
        paint(n-1,x,y- pow(2,n-1));
        paint(n-1,x- pow(2,n-2)*2,y);
    }

}
int main(void)
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            map[i][j]=' ';
        }
    }
    int y=pow(2,n);
    int x=pow(2,n+1);
    paint(n, x, y);
    for (int i = y; i >=1 ; --i) {
        for (int j = 1; j <= x; ++j) {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}