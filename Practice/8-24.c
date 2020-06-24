//
// Created by JokerMss on 2020/6/21.
//

#include <stdio.h>

int main() {
    int fun(int x, int y, int(*p)(int, int));
    int max(int, int);
    int min(int, int);
    int add(int, int);
    int a, b, n;
    printf("please input a and b.\n");
    scanf("a=%d, b=%d", &a, &b);
    printf("Please choose 1, 2 or 3: >");
    scanf("%d", &n);
    if (n == 1) fun(a, b, max);
    else if (n == 2) fun(a, b, min);
    else if (n == 3) fun(a, b, add);
    return 0;
}

int fun(int x, int y, int(*p)(int, int)) {
    int res;
    res = (*p)(x, y);
    printf("%d", res);
}

int max(int x, int y) {
    int max;
    if (x > y) max = x;
    else max = y;
    printf("max==");
    return max;
}

int min(int x, int y) {
    int min;
    if (x < y) min = x;
    else min = y;
    printf("min==");
    return min;
}

int add(int x, int y) {
    int sum;
    sum = x + y;
    printf("sum==");
    return sum;
}