//
// Created by JokerMss on 2020/6/11.
//
// ţ�ٵ������󷽳̵ĸ�
//
#include "stdio.h"
#include "math.h"

main() {
    float solution(float a, float b, float c, float d);   //��ţ�ٵ������󷽳̵ĸ�
    float a, b, c, d, x;
    printf("�����뷽�̵�ϵ����");
    scanf("%f %f %f %f", &a, &b, &c, &d);
    x = solution(a, b, c, d);
    printf("���󷽳̵ĸ�Ϊ x = %f", x);
}

float solution(float a, float b, float c, float d) {
    float x0, x = 1.5, f, fd, h;                         //f�Ƿ��̵�ֵ��fd�Ƿ�����֮���ֵ
    do {
        x0 = x;
        f = a * x0 * x0 * x0 + b * x0 * x0 + c * x0 + d;
        fd = 3 * a * x0 * x0 + 2 * b * x0 + c;
        h = f / fd;
        x = x0 - h;
    } while (fabs(x - x0) >= 1e-5);
    return x;
}