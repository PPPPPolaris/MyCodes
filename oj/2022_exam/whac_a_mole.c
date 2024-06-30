//
// Created by MR on 2023/12/26.
//
#include <stdio.h>
#include <math.h>
#define MAX 75
int n,m,d;
int map[MAX][MAX]={0};
int firstValue(int i,int j){
    int ans=0;
    for (int k = 0; k <= d ; ++k) {
        for (int l = 0; l <= d-k ; ++l) {
            ans+=map[i+k][j+l];
        }
    }
    return ans;
}
int right(int i,int j){
    int ans=0;
    for (int k = -d; k <= d ; ++k) {
        ans+=map[i+k][j+ d-abs(k)];
    }
    return ans;
}
int left(int i,int j){
    int ans=0;
    for (int k = -d; k <= d ; ++k) {
        ans+=map[i+k][j-(d- abs(k))];
    }
    return ans;
}
int up(int i,int j){
    int ans=0;
    for (int k = -d; k <= d ; ++k) {
        ans+=map[i-(d- abs(k))][j+k];
    }
    return ans;
}
int down(int i,int j){
    int ans=0;
    for (int k = -d; k <= d ; ++k) {
        ans+=map[i+(d- abs(k))][j+k];
    }
    return ans;
}
int main(void){
    scanf("%d%d%d",&n,&m,&d);
    for (int i = d+1; i <= d+n; ++i) {
        for (int j = d+1; j <= d+m ; ++j) {
            scanf("%d",&map[i][j]);
        }
    }
    int max= firstValue(d+1,d+1);
    int res[MAX][MAX]={0};
    res[d+1][d+1]= firstValue(d+1,d+1);
    int count=0;
    for (int i = d+1; i <= d+n ; ++i) {
        if((i-d)%2 !=0) {
            for (int j = d + 1; j <= d + m; ++j) {
                if (i == d + 1 && j == d + 1)
                    continue;
                else if ((i - d) % 2 != 0) {//go right
                    if (j == d + 1)
                        res[i][j] = res[i - 1][j] + down(i, j) - up(i - 1, j);
                    else
                        res[i][j] = res[i][j - 1] + right(i, j) - left(i, j - 1);
                }
                if (res[i][j] > max) {
                    max = res[i][j];
                }
            }
        } else{
            for (int j = d+m; j >= d+1 ; --j) {
                if (j == d + m)
                    res[i][j] = res[i - 1][j] + down(i, j) - up(i - 1, j);
                else
                    res[i][j] = res[i][j + 1] + left(i, j) - right(i, j + 1);
                if (res[i][j] > max) {
                    max = res[i][j];
                }
            }
        }
    }
    for (int i = d+1; i <= d+n ; ++i) {
        for (int j = d+1; j <= d+m ; ++j) {
            if(res[i][j]==max){
                count++;
            }
        }
    }
    printf("%d %d\n",max,count);
    for (int i = d+1; i <= d+n ; ++i) {
        for (int j = d+1; j <= d+m ; ++j) {
            if(res[i][j]==max)
                printf("%d %d\n",i-d,j-d);
        }
    }
    return 0;
}