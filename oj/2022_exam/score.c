//
// Created by MR on 2023/12/29.
//
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
int b[3];
int max=INT_MIN;
int cmp(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}
void multiply(int num[3]){
    int tmp[3];
    tmp[0]=num[0],tmp[1]=num[1],tmp[2]=num[2];
    qsort(tmp,3,sizeof (int),cmp);
    int res=0;
    for (int i = 0; i < 3; ++i) {
        res+=b[i] * tmp[i];
    }
    if(res>max)
        max=res;
}
int main(void){
    int num[3][3]={0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d",&num[i][j]);
        }
    }
    scanf("%d%d%d",&b[0],&b[1],&b[2]);
    qsort(b,3,sizeof (int),cmp);
    int tmp[3]={0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tmp[0]=num[i][j];
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    if(k==i && l==j)
                        continue;
                    else
                        tmp[1]=num[k][l];
                    for (int m = 0; m < 3; ++m) {
                        for (int n = 0; n < 3; ++n) {
                            if((m==k && n==l) || (m==i && n==j) || (i==k && k==m) || (j==l && l==n)
                            || (abs(i-k)==abs(j-l) && abs(i-m)== abs(j-n) && abs(k-m)== abs(l-n)))
                                continue;
                            else{
                                tmp[2]=num[m][n];
                                multiply(tmp);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d",max);
    return 0;
}