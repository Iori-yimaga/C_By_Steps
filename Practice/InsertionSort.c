//
// Created by jokermss on 2020/7/1.
//
#include <stdio.h>

void insertion_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 1; i < len; i++) {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

int main() {
    int arr[] = {22, 34, 3, 32, 65, 67, 93, 26, 57, 38, 67, 78};
    int len = (int) sizeof(arr) / sizeof(*arr);
    insertion_sort(arr, len);
    int i;
    for (i = 0; i < len - 1; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}