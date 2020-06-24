//
// Created by JokerMss on 2020/6/10.
// ĳ�˴�1990��1��1����ʼ�������������ɹ��������ô��������Ժ��ĳһ���Ǵ��㻹��ɹ����
//
// ���㻹��ɹ��
//

#include "stdio.h"
/* �������ڵĽṹ��*/
typedef struct date{
    int year;
    int month;
    int day;
}DATE;
int countDay(DATE);
int isLeapYear(int);
int main(void){
    // 1�������1990��1��1�տ�ʼ��ĳһ���ж�����
    DATE today;
    int totalDay;                               /* ������*/
    int result;                                 /* ����5������*/
    printf("Please input a day YYYY-MM-DD: \n");
    scanf("%d%d%d",&today.year, &today.month, &today.day);
    totalDay = countDay(today);

    // 2�������ɹ��������Ϊ5�죬���Խ�����������
    result = totalDay % 5;

    // 3����������ȥ�ж������ڴ��㻹��ɹ����1��2��3�Ǵ��㣬����ɹ����
    if (result > 0 && result <= 3){
        printf("�������:X");
    } else{
        printf("����ɹ��:)");
    }
}

/* �ж��Ƿ�Ϊ���꣬�Ƿ���1�����򷵻�0*/
int isLeapYear(int year){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return 1;
    } else{
        return 0;
    }
}

/* ����ָ�����ھ���19901��1�յ�����*/
int countDay(DATE currentDay){
    int perMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDay = 0, year, i;
    /* ���ָ������֮ǰ��ÿһ��������ۼӺ�*/
    for(year = 1990; year < currentDay.year; year++){
        if(isLeapYear(year)){
            totalDay += 366;
        } else{
            totalDay += 365;
        }
    }
    /* ���Ϊ���꣬������29��*/
    if(isLeapYear(currentDay.year)){
        perMonth[2] += 1;
    }
    /* ������������ۼӵ�totalDay��*/
    for (int i = 0; i < currentDay.month; i++) {
        totalDay += perMonth[i];
    }
    /* �����µ������ۼӵ�totalDay��*/
    totalDay += currentDay.day;
    /* ����totalDay*/
    return totalDay;
}