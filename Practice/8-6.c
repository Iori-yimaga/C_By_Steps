//
// Created by JokerMss on 2020/6/21.
//

#include <stdio.h>
int main(){
    int a[10];
    int *p = &a[0];
    for ( p = a; p < a+10; p++) {
        scanf("%d", p);
    }
    for ( p = a; p < a+10; p++) {
        printf("%d ", *p);
    }
    return 0;
}