#include<stdio.h>

typedef struct SqStack {
    char str[100];
    int top;
}SqStack;

void Push(SqStack* S, char c) {
    S->top++;
    S->str[S->top] = c;
}

void Pop(SqStack* S, char* c) {
    *c = S->str[S->top];
    S->top--;
}

int Empty(SqStack* S) {
    return S->top == -1;
}

void Init(SqStack* S) {
    S->top = -1;
}

char LeftBracket(char right) {
    if (right == ')')
        return '(';
    else if (right == ']')
        return '[';
    else if (right == '}')
        return '{';
    return 0;
}

int BracketsCheck(char* str) {
    SqStack S;
    Init(&S);
    int i = 0;
    while (str[i] != '\0') {
        switch (str[i]) {
            case '(':
            case '[':
            case '{':
                Push(&S, str[i]);
                i++;
                break;
            case ')':
            case ']':
            case '}':
                if (!Empty(&S)) {
                    char c;
                    Pop(&S, &c);
                    if (c == LeftBracket(str[i]))
                        i++;
                    else
                        return 0;
                }
                else
                    return 0;
                break;
            default:
                i++;
        }
    }
    return Empty(&S);
}

int main() {
    char* str = "{[1+2*(5-2)]*4*{2+6}}";
    int pass = BracketsCheck(str);
    if (pass) {
        printf("匹配成功!");
    }
    else {
        printf("匹配失败!");
    }
    return 0;
}