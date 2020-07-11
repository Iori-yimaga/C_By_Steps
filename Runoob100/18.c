//
// Created by jokermss on 2020/7/11.
//
/**
 * 题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。

程序分析：关键是计算出每一项的值。
 * */
#include <stdio.h>

int main() {
    int sum = 0, a, m, n, t;
    printf("请输入ａ和ｎ：＞");
    scanf("%d %d", &a, &n);
    t = a;
    m = n;
    while (n > 0) {
        sum += t;
        a *= 10;
        t += a;
        n--;
    }
    printf("a + aa + aaa + ... +(%d个)a = %d", m, sum);
    return 0;
}