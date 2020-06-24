//
// Created by JokerMss on 2020/6/11.
// 有一对兔子，从出生后的每三月都会生一对兔子，30个月内每个月的兔子总数为多少
//
// 兔子产子问题
/*
 *        不满一个月的为小兔子
 * 假设    满一个月不满两个月的为中兔子
 *        两个月以上的为老兔子
 *
 *  兔子的总数可以构成Fibonacci数列(迭代循环)
 * */
#include "stdio.h"
int main(){
    long fib1 = 1, fib2 = 1, fib;
    int i;
    printf("%12ld %12ld", fib1, fib2);   //输出第一个月和第二个月的兔子数
    for (int i = 3; i <= 30; i++) {
        fib = fib1 + fib2;               //迭代求出当前月份的兔子总数
        printf("%12ld", fib);            //输出当前月份的兔子数
        if(i % 4 == 0){
            printf("\n");
        }
        fib2 = fib1;
        fib1 = fib;
    }
}


