//
// Created by JokerMss on 2020/6/21.
//
#include <stdio.h>
#include <string.h>

int main() {
//    char a[] = "I am aw.", b[20];
//    int i;
//    for (i = 0; *(a + i) != '\0'; i++) {
//        *(b + i) = *(a + i);
//    }
//    *(b + i) = '\0';
//    printf("string a is: %s\n", a);
//    printf("string b is: ");
//    for (i = 0; b[i] != '\0'; i++) {
//        printf("%c", b[i]);
//    }

    char c[]="I am a good student!", d[30], *p1, *p2;
    p1=c, p2=d;
    for (;*p1 != '\0'; p1++,p2++) {
        *p2 = *p1;
    }
    *p2 = '\0';
    printf("string c is: %s\n", c);
    printf("string d is: %s", d);
    return 0;
}
