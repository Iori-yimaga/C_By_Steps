//
// Created by jokermss on 2020/7/2.
//

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100    //存储空间的初始分配量
#define STACKINCREMENT 10      //储存空间分配增量
#define OK 1
#define ERROR 0
typedef int StackType;         //栈元素类型

typedef struct {
    StackType *base;           //构造前和销毁后，base的值为NULL(栈底指针)
    StackType *top;            //栈顶指针
    int stacksize;             //当前已经分配的存储空间，以元素为单位
} SqStack;                      //顺序栈

//初始化
int InitStack(SqStack *p) {
    p->base = (StackType *) malloc(STACK_INIT_SIZE * sizeof(StackType));
    if (p->base == NULL) {
        return ERROR;
    }   //内存分配失败
    p->top = p->base;            //栈顶与栈底相同表示空栈
    p->stacksize = STACK_INIT_SIZE;
    return OK;
}

//判断是否为空
int EmptyStack(SqStack *p) {
    if (p->top == p->base) {
        return OK;
    } else {
        return ERROR;
    }
}

//顺序栈的压入
int Push(SqStack *p, StackType e) {
    //如果栈滿则追加空间
    if ((p->top - p->base) >= p->stacksize) {
        p->base = (StackType *) realloc(p->base, (p->stacksize + STACKINCREMENT) * sizeof(StackType));
        //分配失败
        if (p->base == NULL) {
            return ERROR;
        }
        p->top = p->base + p->stacksize;
        p->stacksize += STACKINCREMENT;
    }
    *(p->top) = e;
    (p->top)++;
    return OK;
}

//顺序栈弹出
int Pop(SqStack *p, StackType *e) {
    if (p->top == p->base) {
        return ERROR;
    }
    --(p->top);
    *e = *(p->top);
    return OK;
}

//顺序栈销毁
int DestroyStack(SqStack *p) {
    free(p->base);
    p->base = NULL;
    p->top = NULL;
    p->stacksize = 0;
    return OK;
}

//置空顺序栈
int ClearStack(SqStack *p) {
    p->top = p->base;
    return OK;
}

//获取当前栈中元素个数
int StackLength(SqStack p) {
    return p.top - p.base;
}

//获取当前栈顶元素
int GetTop(SqStack *p, StackType *e) {
    if (p->top > p->base) {
        *e = *(p->top - 1);
        return OK;
    } else {
        return ERROR;
    }
}

//从栈底到栈顶对每个元素调用某个函数
int StackTraverse(SqStack p, void (*pfun)(StackType)/*函数指针*/) {
    while (p.top > p.base) {
        pfun(*(p.base)++);
        printf("\n");
    }
    return OK;
}

//打印栈中元素
void print(StackType stack) {
    printf("%d", stack);
}

int main() {
    int n, i;
    StackType *e, a;
    SqStack *pstack, stack;
    pstack = &stack;
    e = (StackType *) malloc(sizeof(StackType));   //为指针e分配内存空间
    InitStack(pstack);                         //初始化栈

    if (EmptyStack(pstack) == 1) printf("-----栈为空-----\n");
    printf("请输入元素个数: >");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        Push(pstack, a);
    }

    if (EmptyStack(pstack) == 0) printf("-----栈不为空-----\n");

    printf("栈的长度为：%d\n", StackLength(stack));
    printf("--------------\n");
    printf("请输入一个入栈元素: >");
    scanf("%d", &a);
    Push(pstack, a);
    printf("--------------\n");
    printf("栈中元素个数为: %d\n", StackLength(stack));
    printf("--------------\n");
    GetTop(pstack, e);
    printf("栈顶元素为: %d\n", *e);
    printf("--------------\n");
    printf("打印栈中的元素:\n");
    StackTraverse(stack, print);
    printf("---弹出栈顶元素---\n");
    Pop(pstack, e);
    printf("弹出的栈顶元素为:%d\n", *e);
    printf("--------------\n");
    GetTop(pstack, e);
    printf("栈顶元素为:%d\n", *e);
    printf("--------------\n");
    printf("打印栈中的元素:\n");
    StackTraverse(stack, print);
    printf("--------------\n");

    printf("-----清空栈-----\n");
    if (ClearStack(pstack) == 0) printf("已清空栈\n");

    printf("-----销毁栈-----\n");
    if (DestroyStack(pstack) == 0) printf("已销毁栈\n");
    return 0;
}