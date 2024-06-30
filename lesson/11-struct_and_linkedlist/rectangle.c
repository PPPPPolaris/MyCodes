//
// Created by MR on 2023/11/28.
//
#include <stdio.h>
#include "math.h"
struct point{
    double x;
    double y;
};
struct rectangle{
    struct point p1;
    struct point p2;
};
double area(struct rectangle* p){
    double ans=fabs((p->p1.x-p->p2.x)*(p->p1.y-p->p2.y));
    return ans;
}
int main(void){
    struct rectangle r1={{1.0,2.0},{3.0,4.0}};
    printf("%f", area(&r1));
    return 0;
}