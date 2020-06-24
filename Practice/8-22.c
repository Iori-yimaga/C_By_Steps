//
// Created by JokerMss on 2020/6/21.
//

#include <stdio.h>

int main() {
    int max(int, int);
    int (*p)(int, int);
    p = max;
    int a, b, c;
    printf("Please input a and b: >");
    scanf("%d %d", &a, &b);
    c = (*p)(a, b);
    printf("a=%d,b=%d\nmax=%d", a, b, c);
    return 0;
}

int max(int x, int y) {
    int max;
    if (x > y) max = x;
    else max = y;
    return max;
}