#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define MAXSIZE 5

typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int top;                // 栈顶元素
} Stack, *PStack;

status Push(PStack stack, ElemType e)
{
    if (stack->top == MAXSIZE - 1)
        return ERROR;
    stack->top++;
    stack->data[stack->top] = e;
    return OK;
}



int main()
{

    return 0;
}