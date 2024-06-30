//
// Created by MR on 2023/10/15.
//
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int det(char key)
{
    if(key=='-'|| isdigit(key))
        return 0;
    else
        return 1;
}//检查一个字符是否只是-、1、2、、、9中的一个，如果是则函数返回值为0
int main(void)
{
    int n;
    scanf("%d",&n);
    int judge[10000]={0};//用于标记是否有非法字符,judge[i]=0代表第i行非法
    int size[10000]={0};
    char result[10000][22]={0};//存储最终结果的字符串
    for (int i = 0; i <= n-1; ++i)
    {
        char ai[16]={0};
        scanf("%15s",ai);//在外层循环中读入n行字符串
        int len;
        len=strlen(ai);
        int bi=0;
        int ci[21]={0};//bi用于存储十进制数，ci为传统三进制数
        for (int j = 0; j < len; ++j) {
            if(det(ai[j])==0)
                judge[i]=1;
            else{
                judge[i]=0;
                break;
            }
            if(ai[j]=='-'&& j!=0){
                judge[i]=0;
                break;
            }
        }
        if(judge[i]==1) {
            if (ai[0] == '-' && (len == 1 || ai[1] == '0'))
                judge[i] = 0;
            else if(ai[0]=='0'&&len>1)
                judge[i]=0;
        }
        if(judge[i]==1)
            bi= atoi(ai);
        int size_of_ci;
        int flag=0;//记录最终结果的长度
        if(bi>0)//对正数进行转化
        {
            for (size_of_ci = 0; bi>0; size_of_ci++) {
                ci[size_of_ci] = bi%3;
                bi = bi / 3;
            }
            for (int j = 0;j<=size_of_ci+1; ++j) {
                //十进制数转换为传统三进制数（ci），ci[0]表示最低位上的数
                if (ci[j] == 2) {
                    result[i][j] = 'Z';
                    ci[j + 1] = ci[j + 1] + 1;
                    flag=flag+1;
                } else if (ci[j] == 3) {
                    result[i][j] = '0';
                    ci[j + 1] = ci[j + 1] + 1;
                    flag=flag+1;
                } else if (ci[j] == 1)
                    result[i][j] = '1';
                else if (ci[j] == 0)
                    result[i][j] = '0';//传统三进制转化为平衡三进制
            }
        } else if(bi<0)//对负数进行转化S
        {
            bi=bi * (-1);
            for (size_of_ci = 0; bi>0; size_of_ci++) {
                ci[size_of_ci] = bi%3;
                bi = bi / 3;
            }
            for (int j = 0;j<=size_of_ci+1; ++j) {
                //十进制数转换为传统三进制数（ci），ci[0]表示最低位上的数
                if (ci[j] == 2) {
                    result[i][j] = '1';
                    ci[j + 1] = ci[j + 1] + 1;
                    flag=flag+1;
                } else if (ci[j] == 3) {
                    result[i][j] = '0';
                    ci[j + 1] = ci[j + 1] + 1;
                    flag=flag+1;
                } else if (ci[j] == 1)
                    result[i][j] = 'Z';
                else if (ci[j] == 0)
                    result[i][j] = '0';//传统三进制转化为平衡三进制
            }

        } else{
            result[i][0]='0';
            size_of_ci=1;
        }
        if(flag==0)
            size[i]=size_of_ci;
        else
            size[i]=size_of_ci+1;
    }
    for (int i = 0; i < n; ++i) {
        if(judge[i] == 1) {
            if(result[i][size[i] - 1]!='0'){
                for (int k = size[i] - 1; k >= 0; --k) {
                    printf("%c", result[i][k]);
                }
            } else if(result[i][size[i] - 1]=='0'&&result[i][size[i]-2]!=0){
                for (int k = size[i] - 2; k >= 0; --k) {
                    printf("%c", result[i][k]);
                }
            } else
                printf("0");
            printf("\n");
        } else
            printf("Radix Error\n");
    }
    return 0;
}
