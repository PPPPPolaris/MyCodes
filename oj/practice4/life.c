//
// Created by MR on 2023/10/27.
//
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
int main(void)
{
    int n;
    char life[1000][1001]={0};
    scanf("%d %s",&n,life[0]);
    int len=strlen(life[0]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < len; ++j) {
            int bucket[2]={0};
            bool killed=false;
            if(life[i][j]=='.'){
                for (int k = j-3; k <=j+3 ; ++k) {
                    if(life[i][k]=='A')
                        bucket[0]++;
                    else if(life[i][k]=='B')
                        bucket[1]++;
                }
                if(bucket[0]>=2&&bucket[0]<=4&&bucket[1]==0)
                    life[i+1][j]='A';
                else if(bucket[1]>=2&&bucket[1]<=4&&bucket[0]==0)
                    life[i+1][j]='B';
                else
                    life[i+1][j]='.';
            } else if(life[i][j]=='A'){
                for (int k = j-3; k <=j+3 ; ++k) {
                    if(life[i][k]=='A')
                        bucket[0]++;
                    else if(life[i][k]=='B'){
                        life[i+1][j]='.';
                        killed=true;
                    }
                }
                if(killed==false) {
                    if (bucket[0] >= 6 || bucket[0] <= 2)
                        life[i + 1][j] = '.';
                    else
                        life[i + 1][j] = 'A';
                }
            } else{
                for (int k = j-3; k <=j+3 ; ++k) {
                    if(life[i][k]=='B')
                        bucket[1]++;
                    else if(life[i][k]=='A'){
                        life[i+1][j]='.';
                        killed=true;
                    }
                }
                if(killed==false) {
                    if (bucket[1] >= 6 || bucket[1] <= 2)
                        life[i + 1][j] = '.';
                    else
                        life[i + 1][j] = 'B';
                }
            }
        }
    }
    printf("%s",life[n]);
    return 0;
}