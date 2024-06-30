//
// Created by Polaris on 2023/11/24.
//
#include "stdio.h"
#define MAX 90
int main(void){
    int num;
    int len,wid,high;
    scanf("%d",&num);
    while (num--){
        scanf("%d%d%d",&len,&wid,&high);
        char cuboid[MAX][MAX];
        for (int i = 0; i < MAX; ++i) {
            for (int j = 0; j < MAX; ++j) {
                cuboid[i][j]=' ';
            }
        }
        //正面
        for (int i = 2 *wid; i <2 * (wid+high)+1 ; ++i) {
            for (int j = 0; j <= 2 *len; ++j) {
                if(i%2==0) {//+-
                    if(j%2==0)
                        cuboid[i][j]='+';
                    else
                        cuboid[i][j]='-';
                } else{
                    if(j%2==0)
                        cuboid[i][j]='|';
                }
            }
        }//上面
        for (int i = 2 * wid-1; i >=0 ; --i) {
            for (int j = 2 *wid-i; j <= 2*wid-i+2*len ; ++j) {
                if(i%2!=0){
                    if(j%2 !=0)
                        cuboid[i][j]='/';
                } else{
                    if(j%2==0)
                        cuboid[i][j]='+';
                    else
                        cuboid[i][j]='-';
                }
            }
        }//侧面
        for (int j = 2*(len+wid); j >2 *len ; --j) {
            for (int i = 2*(len+wid)+1-j; i <=2*(len+wid)-j+2*high ; ++i) {
                if(j%2==0){
                    if(i%2!=0)
                        cuboid[i][j]='|';
                    else
                        cuboid[i][j]='+';
                } else{
                    if(i%2!=0)
                        cuboid[i][j]='/';
                }
            }
        }
        for (int i = 0; i <=2 * (wid+high) ; ++i) {
            for (int j = 0; j <= 2*(len+wid); ++j) {
                printf("%c",cuboid[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
