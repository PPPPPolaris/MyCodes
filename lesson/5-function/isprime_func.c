//
// Created by Polaris on 2023/10/29.
//
#include <stdbool.h>
#include <math.h>
#include "stdio.h"
bool is_prime(int x)
{
    if(x==1)
        return false;
    else {
        bool flag = true;
        for (int i = 2; i <= sqrt(x + 0.5); ++i) {
            if (x % i == 0) {
                flag = false;
                break;
            }
        }
        return flag;
    }
}
int main(void)
{
    int x;
    printf("Enter a number:");
    scanf("%d",&x);
    if(is_prime(x))
        printf("This number is a prime.");
    else
        printf("This number is not a prime.");
    return 0;
}