//
// Created by JokerMss on 2020/6/21.
//

#include <stdio.h>
#include <string.h>

int main() {
    char arr[100], test;
    int count = 0, word = 0, i;
    gets(arr);
    for ( i = 0; (test = (arr[i])) != '\0' ; i++) {
        if(test == ' '){
            word = 0;
        }else{
            if (word == 0){
                word = 1;
                count ++;
            }
        }
    }
    printf("There are %d words in this line.", count);
    return 0;
}