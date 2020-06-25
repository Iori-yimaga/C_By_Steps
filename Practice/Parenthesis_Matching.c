#include<stdio.h>

//自定义栈类型的结构体
typedef struct SqStack {
    char str[100];
    int top;
} SqStack;

//出栈操作
void Push(SqStack *S, char c) {
    S->top++;
    S->str[S->top] = c;
}

//入栈
void Pop(SqStack *S, char *c) {
    *c = S->str[S->top];
    S->top--;
}

//置空操作
int Empty(SqStack *S) {
    return S->top == -1;
}

//初始化栈
void Init(SqStack *S) {
    S->top = -1;
}

//左匹配括号操作
char LeftBracket(char right) {
    if (right == ')')
        return '(';
    else if (right == ']')
        return '[';
    else if (right == '}')
        return '{';
    return 0;
}

//括号匹配操作
int BracketsCheck(char *str) {
    SqStack S;
    Init(&S);
    int i = 0;
    while (str[i] != '\0') {
        switch (str[i]) {
            case '(':
            case '[':
            case '{':
                Push(&S, str[i]);                         //如果是左括号，直接入栈
                i++;
                break;
            case ')':
            case ']':
            case '}':
                if (!Empty(&S)) {                         //如果是右括号，先检查栈是否为空
                    char c;                               //若不为空，则把顶元素弹出
                    Pop(&S, &c);
                    if (c == LeftBracket(str[i]))
                        i++;
                    else                                  //否则匹配失败
                        return 0;
                } else
                    return 0;
                break;
            default:
                i++;
        }
    }
    return Empty(&S);
}

int main() {
    char *str = "{[1+2*(5-2)]*4*{2+6}}";
    int pass = BracketsCheck(str);
    if (pass) {
        printf("匹配成功!");
    } else {
        printf("匹配失败!");
    }
    return 0;
}