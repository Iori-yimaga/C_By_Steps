//
// Created by jokermss on 2020/7/9.
//
/**
 * 队列的基本操作（顺序表）
 * */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int arr[SIZE];
    int head;
    int tail;
} Queue;

//队列的初始化
void initQueue(Queue *p_queue) {
    p_queue->head = 0;
    p_queue->tail = 0;
}

//队列的清空
void emptyQueue(Queue *p_queue) {
    p_queue->head = 0;
    p_queue->tail = 0;
}

//计算队列长度
int getSize(const Queue *p_queue) {
    return (p_queue->tail - p_queue->head);
}

//判断队列是否为空
int isEmpty(const Queue *p_queue) {
    return !(p_queue->tail - p_queue->head);
}

//判断队列是否满
int isFulled(const Queue *p_queue) {
    return p_queue->tail >= SIZE;
}

//入队
int EnQueue(Queue *p_queue, int val) {
    if (isFulled(p_queue)) {
        return 0;
    } else {
        p_queue->arr[p_queue->tail] = val;
        p_queue->tail++;
        return 1;
    }
}

//访问元素（出队）
int queue_pop(Queue *p_queue, int *p_num) {
    if (isEmpty(p_queue)) {
        return 0;
    } else {
        *p_num = p_queue->arr[p_queue->head];
        p_queue->head++;
        return 1;
    }
}

//访问元素（不出队）
int queue_front(const Queue *p_queue, int *p_num) {
    if (isEmpty(p_queue)) {
        return 0;
    } else {
        *p_num = p_queue->arr[p_queue->head];
        return 1;
    }
}

int main() {
    Queue qu;
    int y;
    initQueue(&qu);
    EnQueue(&qu, 1);
    EnQueue(&qu, 2);
    EnQueue(&qu, 3);
    EnQueue(&qu, 4);

    printf(">>>%d\r\n", getSize(&qu));
    queue_front(&qu, &y);
    printf(">%d\r\n", y);
    printf(">>%d\r\n", getSize(&qu));

    queue_pop(&qu, &y);
    printf(">%d\r\n", y);
    printf(">>%d\r\n", getSize(&qu));

    EnQueue(&qu, 5);

    queue_pop(&qu, &y);
    printf(">%d\r\n", y);
    printf(">>%d\r\n", getSize(&qu));

    while (qu.tail != qu.head) {
        qu.head = qu.head + 1;
        printf("当前队列值=%d\n", qu.arr[qu.head]);
    }
    return 0;
}