//
// Created by JokerMss on 2020/6/10.
// С����5���飬Ҫ���A��B��C��λС���ѣ���ÿ��ÿ��ֻ�ܽ�һ����������ж����ֲ�ͬ�Ľ跨
// ���鷽��֪����
//
// ��ٷ�������ѭ��

#include "stdio.h"
int main(){
    int a, b, c, i = 0;
    printf("A��B��C������ѡ��ı�ŷֱ�Ϊ: \n");
    for (int a = 1; a <= 5; a++) {
        for (int b = 1; b <= 5; b++) {
            for (int c = 1; c <= 5; c++) {
                if(a != b && a != c && b != c){
                    printf("A��%2d,B��%2d,C��%2d ", a, b, c);
                    i++;
                    if(i % 4 == 0){printf("\n");}
                }
            }
        }
    }
    printf("һ����%d�ֽ��ķ���\n", i);
    return 0;
}