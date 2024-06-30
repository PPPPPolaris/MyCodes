//
// Created by Polaris on 2023/11/19.
//
#include <stdbool.h>
#include "stdio.h"
#define MAX 10
#define PIG_1 1
#define PIG_2 2
#define PIG_4 4
bool chess_judge(int chess[MAX][MAX],int player,int win,int size)
{
    bool is_win=false;
    //横着胜
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            if(c<=size-win)
            {
                for (int i = c; i <c+win ; ++i) {
                    if(chess[r][i]!=player) {
                        is_win = false;
                        break;
                    } else
                        is_win=true;
                }
                if(is_win==true)
                    return true;
            }
            if(r<=size-win)
            {
                for (int i = r; i <r+win ; ++i) {
                    if(chess[i][c]!=player) {
                        is_win = false;
                        break;
                    } else
                        is_win=true;
                }
                if(is_win==true)
                    return true;
            }
            if(r<=size-win && c<=size-win)
            {
                for (int i = 0; i <win ; ++i) {
                    if(chess[r+i][c+i]!=player){
                        is_win=false;
                        break;
                    } else
                        is_win=true;
                }if (is_win==true)
                    return true;
            }
            if(r>=win-1 && c<=size-win)
            {
                for (int i = 0; i <win ; ++i) {
                    if(chess[r-i][c+i]!=player){
                        is_win=false;
                        break;
                    } else
                        is_win=true;
                }if (is_win==true)
                    return true;
            }
        }
    }
    return is_win;
}
int main(void)
{
    int game,win;
    scanf("%d%d",&game,&win);
    while (game--)
    {
        int chess[MAX][MAX]={0};
        int size;
        scanf("%d",&size);
        for (int r = 0; r < size; ++r) {
            for (int c = 0; c < size; ++c) {
                scanf("%d",&chess[r][c]);
            }
        }
        bool pig1_win= chess_judge(chess,PIG_1,win,size);
        bool pig2_win= chess_judge(chess,PIG_2,win,size);
        bool pig4_win= chess_judge(chess,PIG_4,win,size);
        if(pig1_win && !pig2_win && !pig4_win)
            printf("%d\n",PIG_1);
        else if(pig2_win && !pig1_win && !pig4_win)
            printf("%d\n",PIG_2);
        else if(pig4_win && !pig1_win && !pig2_win)
            printf("%d\n",PIG_4);
        else
            printf("draw\n");

    }
    return 0;
}
