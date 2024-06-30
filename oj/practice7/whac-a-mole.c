//
// Created by MR on 2023/11/22.
//
#include "stdio.h"
#define MAX 700
int tmp_ans[MAX][MAX]={0};
int Value[MAX][MAX]={0};
int n,m,d;
int ansN;
int loc_max[360000][2];
int beat(int r,int c){
    int ans=0;
    for (int i = -d; i <= 0 ; ++i) {
        for (int j = -(d+i); j <= d+i ; ++j) {
               ans+=Value[r+i][c+j];
        }
    }
    for (int i = 1; i <=d ; ++i) {
        for (int j =i-d ; j <=d-i ; ++j) {
            ans+=Value[r+i][c+j];
        }
    }
    return ans;
}
int left(int r,int c){
    int ans=0;
    for (int i = 0; i <=d ; ++i) {
        ans+=Value[r+i][c-d+i];
    }
    for (int i = -d; i <0 ; ++i) {
        ans+=Value[r+i][c-d-i];
    }
    return ans;
}
int right(int r,int c){
    int ans=0;
    for (int i = 0; i <=d ; ++i) {
        ans+=Value[r+i][c+d-i];
    }
    for (int i = -d; i <0 ; ++i) {
        ans+=Value[r+i][c+d+i];
    }
    return ans;
}
int up(int r,int c){
    int ans=0;
    for (int i = 0; i <=d ; ++i) {
        ans+=Value[r-d+i][c+i];
    }
    for (int i = -d; i <0 ; ++i) {
        ans+=Value[r-d-i][c+i];
    }
    return ans;
}
int down(int r,int c){
    int ans=0;
    for (int i = 0; i <=d ; ++i) {
        ans+=Value[r+d-i][c+i];
    }
    for (int i = -d; i <0 ; ++i) {
        ans+=Value[r+d+i][c+i];
    }
    return ans;
}
int minus(int direction,int r,int c){//1==right,-1==left,0==down
    if(direction==1){
        return right(r,c)- left(r,c-1);
    } else if(direction==-1){
        return left(r,c)- right(r,c+1);
    } else
        return down(r,c)- up(r-1,c);
}
int main(void)
{
    scanf("%d%d%d",&n,&m,&d);
    for (int r = 1+d; r <=n+d ; ++r) {
        for (int c = 1+d; c <=m+d ; ++c) {
            scanf("%d",&Value[r][c]);
        }
    }
    tmp_ans[1+d][1+d]= beat(1+d,1+d);
    for (int r = 1+d; r <=n+d ; ++r) {
        if((r-d)%2!=0) {//right
            for (int c = 1 + d; c <= m + d; ++c) {
                if(r==1+d && c==1+d)
                    continue;
                if (c == 1 + d)
                    tmp_ans[r][c] = tmp_ans[r - 1][c] + minus(0, r, c);
                else
                    tmp_ans[r][c] = tmp_ans[r][c - 1] + minus(1, r, c);


            }
        } else{//left
            for (int c = m+d; c >=1+d ; --c) {
                if(c==m+d)
                    tmp_ans[r][c]=tmp_ans[r-1][c]+ minus(0,r,c);
                else
                    tmp_ans[r][c]=tmp_ans[r][c+1]+ minus(-1,r,c);
            }
        }
    }
    int max_value=tmp_ans[1+d][1+d];
    for (int i = 1+d; i <=n+d ; ++i) {
        for (int j = 1 + d; j <= m + d; ++j) {
            if (tmp_ans[i][j] > max_value) {
                max_value = tmp_ans[i][j];
            }
        }
    }
    for (int i = 1+d; i <=n+d ; ++i) {
        for (int j = 1+d; j <=m+d ; ++j) {
            if(tmp_ans[i][j]==max_value) {
                loc_max[ansN][0]=i-d;
                loc_max[ansN][1]=j-d;
                ansN++;
            }
        }
    }
    printf("%d %d\n",max_value,ansN);
    for (int i = 0; i < ansN; ++i) {
        printf("%d %d\n",loc_max[i][0],loc_max[i][1]);
    }
    return 0;
}