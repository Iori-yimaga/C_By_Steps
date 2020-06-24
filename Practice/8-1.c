//
// Created by JokerMss on 2020/6/20.
//
#include <stdio.h>
int main(){
    int a = 100, b = 200;
    int *p1, *p2;
    p1 = &a;
    p2 = &b;
    printf("p1=%d, p2=%d", *p1, *p2);
}
