//
// Created by JokerMss on 2020/6/10.
// 小明有5本书，要借给A、B、C三位小朋友，若每人每次只能借一本，则可以有多少种不同的借法
// 借书方案知多少
//
// 穷举法、三重循环

#include "stdio.h"
int main(){
    int a, b, c, i = 0;
    printf("A、B、C三人所选书的编号分别为: \n");
    for (int a = 1; a <= 5; a++) {
        for (int b = 1; b <= 5; b++) {
            for (int c = 1; c <= 5; c++) {
                if(a != b && a != c && b != c){
                    printf("A借%2d,B借%2d,C借%2d ", a, b, c);
                    i++;
                    if(i % 4 == 0){printf("\n");}
                }
            }
        }
    }
    printf("一共有%d种借阅方法\n", i);
    return 0;
}