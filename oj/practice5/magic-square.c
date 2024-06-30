//
// Created by MR on 2023/10/27.
//
#include <stdbool.h>
#include "stdio.h"
int main(void)
{
    int n;
    scanf("%d",&n);
    int square[99][99]={0};
    bool taken[99][9]={false};
    square[0][(n-1)/2]=1;
    square[n-1][(n-1)/2+1]=2;
    taken[0][(n-1)/2]=taken[n-1][(n-1)/2+1]=true;
    int row=n-1;
    int col=(n-1)/2+1;
    for (int i = 3; i <=n*n ; ++i) {
        if(row-1>=0 && col+1<n)
        {
            if(taken[row-1][col+1]==false){
               square[row-1][col+1]=i;
               taken[row-1][col+1]=true;
               row--;
               col++;
            } else{
                square[row+1][col]=i;
                taken[row+1][col]=true;
                row++;
            }
        } else if(row-1<0 && col+1>=n){
            if(taken[n-1][0]==false){
               square[n-1][0]=i;
               taken[n-1][0]=true;
               row=n-1;
               col=0;
            } else{
                square[row+1][col]=i;
                taken[row+1][col]=true;
                row++;
            }
        } else if(row-1<0 && col+1<n){
            if(taken[n-1][col+1]==false){
                square[n-1][col+1]=i;
                taken[n-1][col+1]=true;
                row=n-1;
                col++;
            } else{
                square[row+1][col]=i;
                taken[row+1][col]=true;
                row++;
            }
        } else if(row-1>=0 && col+1 >=n){
            if(taken[row-1][0]==false){
                square[row-1][0]=i;
                taken[row-1][0]=true;
                row--;
                col=0;
            }else{
                square[row+1][col]=i;
                taken[row+1][col]=true;
                row++;
            }
        }

    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ",square[i][j]);
        }
        printf("\n");
    }
    return 0;
}