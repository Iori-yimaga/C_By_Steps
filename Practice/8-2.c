//
// Created by JokerMss on 2020/6/20.
//
#include <stdio.h>
int main(){
    int a, b, *Max, *Min, *tmp;
    scanf("%d %d", &a, &b);
    Max = &a;
    Min = &b;
    if(a < b){
        tmp = Max;
        Max = Min;
        Min = tmp;
    }
    printf("a=%d, b=%d\n", a, b);
    printf("Max=%d, Min=%d", *Max, *Min);
    return 0;
}
