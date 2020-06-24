//
// Created by JokerMss on 2020/6/20.
//

#include <stdio.h>
int main(){
    char c;
    c = getchar();
    while (c != '\n'){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            if (c >= 'W' && c <= 'Z' || c >= 'w' && c <= 'z'){
                c -= 22;
            }else{
                c += 4;
            }
        }
        printf("%c", c);
        c = getchar();
    }
    return 0;
}