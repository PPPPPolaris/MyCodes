//
// Created by MR on 2023/12/8.
//
#include "stdio.h"
#include "math.h"
#define MAX 320000
int Size[MAX];
int ID[MAX];
int count;
void Query(void){
    printf("%d\n",count);
    for (int i = 0; i < count; ++i) {
        printf("%d ",ID[i]);
    }
    printf("\n");
}
void push(int index){//from index to the end
    for (int i = count-1; i >=index ; --i) {
        Size[i+1]=Size[i];
        ID[i+1]=ID[i];
    }
}
void allocate(int id,int need){
    while (1) {
        for (int i = 0; i < count; ++i) {
            if (Size[i] == need && ID[i] == 0) {
                ID[i] = id;
                return;
            }
        }
        for (int i = 0; i < count; ++i) {
            if (Size[i] > need && ID[i] == 0) {
                push(i + 1);
                count++;
                Size[i]--;
                Size[i + 1] = Size[i];
                ID[i] = ID[i + 1] = 0;
                break;
            }
        }
    }
}
int main(void){
    int n,q;
    scanf("%d%d",&n,&q);
    Size[0]=n;
    count++;
    while (q--){
        char ope[3]={0};
        scanf("%s",ope);
        if(ope[0]=='Q'){
            Query();
        } else{
            int id,size;
            scanf("%d%d",&id,&size);
            int need= (int)ceil(log2(size));
            allocate(id,need);
        }
    }
    return 0;
}