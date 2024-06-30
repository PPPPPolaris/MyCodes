//
// Created by MR on 2023/10/27.
//
#include <stdbool.h>
#include <math.h>
#include "stdio.h"
bool is_prime(int x){
    bool judge=true;
    for (int i = 2; i <= sqrt(x+0.5); ++i) {
        if(x%i==0)
            judge=false;
    }
    if(judge==true && x!=1)
        return true;
    else
        return false;
}
int count_num(int x){
    int count=0;
    do {
        x/=10;
        count++;
    } while (x>0);
    return count;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    int count_prime=0;
    for (int i = 2; i <=n ; ++i) {
        int count= count_num(i);
        int num=i;
        int turn=0;
        do {
            turn=turn+(num%10)*pow(10,count-1);
            num/=10;
            count--;
        } while (num>0);
        if(is_prime(turn)==true&& is_prime(i)==true)
            count_prime++;
    }
    printf("%d",count_prime);
    return 0;
}