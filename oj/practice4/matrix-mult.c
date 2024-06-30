//
// Created by MR on 2023/10/21.
//
#include "stdio.h"
int main(void)
{
    int m,n,p;
    scanf("%d %d %d",&m,&n,&p);
    int A[100][100];
    int B[100][100];
    int C[100][100]={0};
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&A[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            scanf("%d",&B[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j]+=A[i][k]*B[k][j];
            }
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}