//
// Created by jokermss on 2020/7/9.
//
/**
 * 二叉树的层次遍历
 * 借助栈
 * */

#include <stdio.h>
#include <malloc.h>
#include "opQueue.c"

typedef int ElemType;

typedef struct BiTree {
    struct BTree *lChild;
    ElemType data;
    struct BTree *rChild;
} BiNode, *BiTree;
Queue *Q;
int n;
void LevelOrder(BiTree T){
    initQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!isEmpty(Q)){
        queue_pop(Q,p);
        queue_front(Q,n);
        if(p->lChild!=NULL){
            EnQueue(Q,p->lChild);
        }
        if (p->rChild!=NULL){
            EnQueue(Q,p->rChild);
        }
    }
}
