//
// Created by JokerMss on 2020/6/11.
// 甲：牌照的前两位数字相同
// 乙：牌照的后两位数字相同，但与前两位不同
// 丙：四位的车号刚好是一个整数的平方
//
// 抓交通肇事罪犯
/*
 * 涉及到求解不定方程组的问题
 * 一般采用穷举法
 * */
#include "stdio.h"
int main(){
    int i, j, k, temp;                      //i代表前两位数字，j代表后两位，k代表车牌号
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            //判断前两位和后两位是否不同
            if(i != j){
                // 组成四位车牌号
                k = i * 1000 + i * 100 + j * 10 + j;
                //判断k是否是某个整数的平方，若是则输出k
                for (int temp = 31; temp <= 99; temp++) {
                    if(temp * temp == k){
                        printf("车牌号为%d", k);
                    }
                }
            }
        }
    }
    return 0;
}