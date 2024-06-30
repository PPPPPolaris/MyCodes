//
// Created by MR on 2023/12/17.
//
#include "stdio.h"
#include "stdlib.h"
#define MAX 25
#define N_MAX 1005
struct person{
    char name[MAX];
    int grade_A;
    int grade_B;
    int grade_C;
};
struct team{
    char team_name[MAX];
    struct person player[11];
    int ave_gradeA,ave_gradeB,ave_gradeC;
};
void read_person(struct person *PERSON){
    scanf("%s%d%d%d",PERSON->name,&(PERSON->grade_A),&(PERSON->grade_B),&(PERSON->grade_C));
}
void read_team(struct team *TEAM){
    scanf("%s",TEAM->team_name);
    for (int i = 0; i < 11; ++i) {
        read_person(&(TEAM->player[i]));
    }
}
int ave_gradeA(struct team *TEAM){
    int sum=0;
    for (int i = 0; i < 11; ++i) {
        sum+=TEAM->player[i].grade_A;
    }
    return sum;
}
int ave_gradeB(struct team *TEAM){
    int sum=0;
    for (int i = 0; i < 11; ++i) {
        sum+=TEAM->player[i].grade_B;
    }
    return sum;
}
int ave_gradeC(struct team *TEAM){
    int sum=0;
    for (int i = 0; i < 11; ++i) {
        sum+=TEAM->player[i].grade_C;
    }
    return sum;
}
int cmpA(const void *a,const void *b){
    return ((struct team *)a)->ave_gradeA > ((struct team *)b)->ave_gradeA? -1:1;
}
int cmpB(const void *a,const void *b){
    return ((struct team *)a)->ave_gradeB > ((struct team *)b)->ave_gradeB? -1:1;
}
int cmpC(const void *a,const void *b){
    return ((struct team *)a)->ave_gradeC > ((struct team *)b)->ave_gradeC? -1:1;
}
void display(struct team TEAM[],int num){
    for (int i = 0; i < num; ++i) {
        printf("%s ",TEAM[i].team_name);
    }
    printf("\n");
}
int main(void){
    int num;
    scanf("%d",&num);
    struct team TEAM[N_MAX]={0};
    int i=0;
    while (i!=num){
        read_team(&(TEAM[i]));
        TEAM[i].ave_gradeA= ave_gradeA(&(TEAM[i]));
        TEAM[i].ave_gradeB= ave_gradeB(&(TEAM[i]));
        TEAM[i].ave_gradeC= ave_gradeC(&(TEAM[i]));
        i++;
    }
    qsort(TEAM,num,sizeof (TEAM[0]),cmpA);
    display(TEAM,num);
    qsort(TEAM,num,sizeof (TEAM[0]),cmpB);
    display(TEAM,num);
    qsort(TEAM,num,sizeof (TEAM[0]),cmpC);
    display(TEAM,num);
    return 0;
}