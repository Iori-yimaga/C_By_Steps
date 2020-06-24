//
// Created by JokerMss on 2020/6/20.
//
#include <stdio.h>

int main() {
    void swap(int *p1, int *p2);
    int a, b;
    int *p1, *p2;
    printf("Please input two numbers!\n");
    scanf("%d %d", &a, &b);
    p1 = &a;
    p2 = &b;
    if (a < b) swap(p1, p2);
    printf("max=%d, min=%d", *p1, *p2);
    return 0;
}

void swap(int *p1, int *p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
