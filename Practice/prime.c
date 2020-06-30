//
// Created by jokermss on 2020/6/30.
//

#include <stdio.h>

int isPrime(int num) {
    int flag = 0;
    if (num > 2){
        for (int i = 2; i < num/2; i++) {
            if(num % i == 0){
                flag = 1;
            }
        }
    }
    return flag;
}

int main() {
    int num;
    printf("Please enter a number: >");
    scanf("%d", &num);
    printf(isPrime(num) ? "Yes" : "No");
    return 0;
}