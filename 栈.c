/** 
 * 栈（stack）： 是仅在表尾（栈顶）进行插入和删除操作的线性表(last in first out) LIFO
 * 允许插入和删除操作的一端称为栈顶（top），另一端称为栈底（bottom），不含任何
 * 数据元素的栈称为空栈，栈又称为先进后出的线性表，简称LIFO结构
 *  
 * 注意：最新进栈的不一定最后出，因为存在进一个出一个的情况 
 *      例如：1、2、3进，3、2、1出；
 *           1进，1出，2进，2出，3进，3出
 */
// ======================================================================== //
/**  
 应用
1.函数调用 :在函数f中调用另一个g函数，在g函数中调用k函数
执行到要调用g函数位置，先把g函数执行后下一句的地址以及变量压栈，
执行g函数，执行到调用k函数的位置，再把k函数执行后的下一句压栈，
然后执行k函数，执行后取出栈顶元素，赋给CPU，执行g函数中调用k函数后的下一句。
2.中断
3.表达式求值：3*2+5/6-4两个栈实现，一个放运算符，一个放数据
4.内存分配：把函数形参压入栈中
5.缓冲处理
6.走迷宫
*/
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/** 
 * @brief  
 * @note    定义节点的结构体  
 * @retval None
 */
typedef struct Node
{
    int data;
    struct Node *next;
} Node, *PNode;

/** 
 * @brief  
 * @note   定义栈的结构体
 * @retval None
 */
typedef struct Stack
{
    PNode top;
    PNode bottom;
} Stack, *PStack;

/** 
 * @brief  
 * @note   初始化栈
 * @param  stack: 
 * @retval None
 */
void initStack(PStack stack)
{
    // 建立一个头结点作为栈底
    stack->bottom = malloc(sizeof(Stack));
    if (stack == NULL)
    {
        printf("内存分配失败\n");
        exit(ERROR);
    }
    stack->top = stack->bottom;
    stack->top->next = NULL;
}

/** 
 * @brief  
 * @note    遍历栈   
 * @param  stack: 
 * @retval None
 */

void traverse(PStack stack)
{
    if (stack->bottom == stack->top)
    {
        printf("栈为空\n");
        return;
    }
    PNode pt = stack->top;
    while (pt != stack->bottom) // 括号中的pt如果换成stack->top， 会修改链表
    {
        printf("%d  ", pt->data);
        pt = pt->next;
    }
    printf("\n");
    return;
}

/** 
 * @brief  
 * @note   入栈
 * @param  stack: 
 * @param  val: 
 * @retval None
 */
status push(PStack stack, int val)
{
    PNode p = malloc(sizeof(Node)); // 生成一个新结点
    if (p->next == NULL)
    {
        printf("动态内存分配失败\n");
        return FALSE;
    }
    p->data = val;
    p->next = stack->top; // NULL
    stack->top = p;
    if (stack->top != NULL)
        return TRUE;
    return FALSE;
}
/** 
 * @brief  
 * @note   出栈
 * @param  stack: 
 * @param  val: 
 * @retval None
 */
status pop(PStack stack)
{
    if (stack->top == stack->bottom)
    {
        printf("栈为空，无法完成出栈操作\n");
        return FALSE;
    }
    PNode p = stack->top;
    stack->top = stack->top->next;
    free(p);
    if (p == NULL)
        return TRUE;
    return FALSE;
}

/** 
 * @brief  
 * @note   清空栈
 * @param  ps: 
 * @retval None
 */
void clear(PStack ps)
{
    // 栈顶和栈底不相等时，循环
    while (ps->top != ps->bottom)
    {
        // 使一个新结点和栈顶指向同一地址
        PNode temp = ps->top;
        // 使栈顶指向下一个结点
        ps->top = ps->top->next;
        // 释放掉以前的栈顶空间
        free(temp);
    }
    return ;
}

int main()
{
    Stack stack;
    initStack(&stack);
    push(&stack, 6);
    push(&stack, 7);
    push(&stack, 8);
    traverse(&stack);
    pop(&stack);
    traverse(&stack);
    clear(&stack);
    traverse(&stack);
    push(&stack, 7);
    traverse(&stack);
    return 0;
}