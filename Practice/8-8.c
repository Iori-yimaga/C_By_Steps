//
// Created by JokerMss on 2020/6/21.
//
#include <stdio.h>

int main() {
    void inv(int a[], int n);
    int i, a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("This is the origin array:\n");
    for (i = 0; i < 10; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
    inv(a, 10);
    printf("This is inverted array:\n");
    for (i = 0; i < 10; i++) {
        printf("%d", a[i]);
    }
    return 0;
}

void inv(int a[], int n) {
    int temp, i, j, m = (n - 1) / 2;
    for (i = 0; i < m; i++) {
        j = n - i - 1;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
