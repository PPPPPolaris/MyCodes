#include "stdio.h"
#include "math.h"
#include "string.h"
int det(char key)
{
    if(key == 48 || key == 49 || key == 90 )
        return 0;
    else
        return 1;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    getchar();
    int d[10005],e[10005];

    for (int i = 0; i <= n-1 ; ++i)
    {
        int turn=0;
        char ai[16];
        int bi[16];
        scanf("%s", ai);
        int len;
        len= strlen(ai);
        int res=0;
        for (int m = 0; m < len; ++m) {
            res = res + det(ai[m]);
            if(res != 0)
                break;
            else if(ai[m] == 'Z')
                bi[m]=-1;
            else if(ai[m] == '1')
                bi[m]=1;
            else if(ai[m]=='0')
                bi[m]=0;

            turn=turn+bi[m] * pow(3,len-1-m);
        }
        if (res != 0) {
            e[i]=1;
        }else {
            e[i]=0;
            d[i] = turn;
        }

    }
    for (int i = 0; i <= n-1 ; ++i) {
        if(e[i]==1)
            printf("Radix Error\n");
        else if(e[i]==0)
            printf("%d\n",d[i]);
    }
    return 0;
}