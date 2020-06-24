//
// Created by JokerMss on 2020/6/11.
//
// 牛顿迭代法求方程的根
//
#include "stdio.h"
#include "math.h"

main() {
    float solution(float a, float b, float c, float d);   //用牛顿迭代法求方程的根
    float a, b, c, d, x;
    printf("请输入方程的系数：");
    scanf("%f %f %f %f", &a, &b, &c, &d);
    x = solution(a, b, c, d);
    printf("所求方程的根为 x = %f", x);
}

float solution(float a, float b, float c, float d) {
    float x0, x = 1.5, f, fd, h;                         //f是方程的值，fd是方程求导之后的值
    do {
        x0 = x;
        f = a * x0 * x0 * x0 + b * x0 * x0 + c * x0 + d;
        fd = 3 * a * x0 * x0 + 2 * b * x0 + c;
        h = f / fd;
        x = x0 - h;
    } while (fabs(x - x0) >= 1e-5);
    return x;
}