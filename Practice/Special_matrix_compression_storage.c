//
// Created by Jokermss on 2020/6/26.
//
/**
 * ��������ѹ���洢
 * ���Ǿ���
 * */
#include <stdio.h>

#define R 5
#define C 5
#define L 16

int main() {
    int B[L];
    int A[R][C] = {{1, 0, 0, 0, 0},
                   {2, 2, 0, 0, 0},
                   {3, 3, 3, 0, 0},
                   {4, 4, 4, 4, 0},
                   {5, 5, 5, 5, 5}};
    int r, c, k;
    printf("�����ǰ����\n");
    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            printf("%d ", A[r][c]);
            if (c == 4) {
                printf("\n");
            }
        }
    }

    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            if (r >= c) {
                k = r * (r + 1) / 2 + c;
                B[k] = A[r][c];
            } else {
                k = L - 1;
                B[k] = 0;
            }
        }
    }

    printf("ѹ���Ľ��Ϊ: \n");
    for (k = 0; k < L; k++) {
        printf("%d", B[k]);
    }
    return 0;
}