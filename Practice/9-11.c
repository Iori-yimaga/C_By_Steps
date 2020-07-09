//
// Created by Jokermss on 2020/6/25.
//
/**
 * 共用体
 * 学生：姓名、号码、性别、职业、班级
 * 教师：姓名、号码、性别、职业、职务
 * */
#include <stdio.h>

struct {
    int num;
    char name[20];
    char sex;
    char job;
    union {
        int class;
        char position[10];
    } category;
} person[2];

int main() {
    int i;
    for (i = 0; i < 2; i++) {
        printf("Please enter the data of person:\n");
        scanf("%d %s %c %c", &person[i].num, person[i].name, &person[i].sex, &person[i].job);
        if (person[i].job == 's') {
            scanf("%d", &person->category.class);
        } else if (person[i].job == 't') {
            scanf("%s", person->category.position);
        } else {
            printf("Input error");
        }
    }
    printf("\n");
    printf("No.    name    sex job class/position\n");
    for (i = 0; i < 2; i++) {
        if (person[i].job == 's') {
            printf("%-6d%-10s%-4c%-4c%-10d\n", person[i].num, person[i].name, person[i].sex, person[i].job,
                   person[i].category.class);
        } else {
            printf("%-6d%-10s%-4c%-4c%-10s\n", person[i].num, person[i].name, person[i].sex, person[i].job,
                   person[i].category.position);
        }
    }
    return 0;
}