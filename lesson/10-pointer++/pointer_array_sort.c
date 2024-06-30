//
// Created by MR on 2023/12/1.
//
#include <stdio.h>
#include <string.h>
#define MAX 10
void swap(char **a,char **b){//there are pointers to be swapped
    char *tmp=*a;
    *a=*b;
    *b=tmp;
    return;
}
void print_pointer_array(char *name[],int len){
    for (int i = 0; i < len; ++i) {
        printf("%s ",name[i]);
    }
}
int main(void){
    char *name[MAX]={"Marry","Lucy","Jerry","Mike","Daniel","Harry","Charlie","Diana","Julia","Taylor"};
    print_pointer_array(name,MAX);
    for (int i = 0; i < MAX; ++i) {
        char *min=name[i];
        int min_loc=i;
        for (int j = i+1; j <MAX ; ++j) {
            if(strcmp(min,name[j])>0){
                min=name[j];
                min_loc=j;
            }
        }
        swap(&name[i],&name[min_loc]);
        //swap(&name[i],&min);//这样导致name【i】的信息进入min而不是name【】，但在这次循环结束后min的空间就相当于被free了
    }
    printf("\n");
    print_pointer_array(name,MAX);
    return 0;
}