//
// Created by Jokermss on 2020/6/23.
//

#include <stdio.h>

struct Student {
    int num;
    char name[20];
    char sex;
    int age;
};

struct Student stu[3] = {{0001, "张三", 'M', 18},
                         {0002, "李四", 'F', 19},
                         {0003, "王武", 'M', 20}};

int main() {
    struct Student *p;
    for (p = stu; p < stu + 3; p++) {
        printf("No.%d name:%s sex:%c age:%d\n", p->num, p->name, p->sex, p->age);
    }
    return 0;
}