//
// Created by JokerMss on 2020/6/10.
// 某人从1990年1月1日起开始“三天打鱼两天晒网”，那么这个人在以后的某一天是打鱼还是晒网？
//
// 打鱼还是晒网
//

#include "stdio.h"
/* 定义日期的结构体*/
typedef struct date{
    int year;
    int month;
    int day;
}DATE;
int countDay(DATE);
int isLeapYear(int);
int main(void){
    // 1、计算从1990年1月1日开始到某一天有多少天
    DATE today;
    int totalDay;                               /* 天数差*/
    int result;                                 /* 除以5的余数*/
    printf("Please input a day YYYY-MM-DD: \n");
    scanf("%d%d%d",&today.year, &today.month, &today.day);
    totalDay = countDay(today);

    // 2、打鱼和晒网的周期为5天，可以将天数除以五
    result = totalDay % 5;

    // 3、根据余数去判断他是在打鱼还是晒网（1、2、3是打鱼，否则晒网）
    if (result > 0 && result <= 3){
        printf("今天打鱼:X");
    } else{
        printf("今天晒网:)");
    }
}

/* 判断是否为闰年，是返回1，否则返回0*/
int isLeapYear(int year){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return 1;
    } else{
        return 0;
    }
}

/* 计算指定日期距离19901月1日的天数*/
int countDay(DATE currentDay){
    int perMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDay = 0, year, i;
    /* 求出指定日期之前的每一天的天数累加和*/
    for(year = 1990; year < currentDay.year; year++){
        if(isLeapYear(year)){
            totalDay += 366;
        } else{
            totalDay += 365;
        }
    }
    /* 如果为闰年，二月有29天*/
    if(isLeapYear(currentDay.year)){
        perMonth[2] += 1;
    }
    /* 将本年的天数累加到totalDay中*/
    for (int i = 0; i < currentDay.month; i++) {
        totalDay += perMonth[i];
    }
    /* 将本月的天数累加到totalDay中*/
    totalDay += currentDay.day;
    /* 返回totalDay*/
    return totalDay;
}