//
// Created by jokermss on 2020/7/7.
//

#include <stdio.h>
#include <malloc.h>

#define NULL 0
#define LEN sizeof(struct stu)
struct stu {
    long int num;
    float score;
    struct stu *next;
};
int n;
struct stu *create() {
    struct stu *head, *p1, *p2;
    n = 0;
    p1 = p2 = (struct stu *) malloc(LEN);
    scanf("%ld,%f", &p1->num, &p1->score);
    head = NULL;
    while (p1->num != 0) {
        n += 1;
        if (n == 1) {
            head = p1;
        } else {
            p2->next = p1;
        }
        p2 = p1;
        p1 = (struct stu *) malloc(LEN);
        scanf("%ld,%f", &p1->num, &p2->score);
    }
    p2->next = NULL;
    return (head);
}

int main() {
    struct stu *p;
    p = create();
    while (p->next != NULL) {
        printf("%ld", p->num);
        p = p->next;
    }
    return 0;
}