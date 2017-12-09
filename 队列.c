#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
 * 队列（queue）是只允许在一端进行插入操作，而在另一端进行删除操作的线性表，先进先出(First In First Out)FIFO,
 *             允许插入的一端称为队尾，允许删除的一端称为队头
 * 队列的应用：所有和事件有关的操作，例如操作系统会先处理你先发送的指令
 *           1、售票口的排队
 *           2、打印机的作业
 * 
 * 出队列    队头            队尾      入队列          
 * <----    a1  a2  a3 ..... an    <-------
 * 
 * front                    rear
 * -----》头结点。。。。。队尾《----
 * 
 * 当队列为空时，front和rear都指向头结点
 * front        rear
 * -----> 头结点 <------
 * 
 */

// 结点结构
typedef struct Node
{
    int data;
    struct Node *next;
}QNode, *Queue;
// 队列的链表结构
typedef struct
{
    Queue front;    // 队头指针
    Queue rear;     // 队尾指针
} LinkQueue;

status EnQueue(LinkQueue *queue, int e)
{
    Queue s = (Queue)malloc(sizeof(QNode));
    if (!s) // 内存分配失败
        exit(OVERFLOW);
    s->data = e;
    s->next = NULL;
    queue->rear->next = e;  
    queue->rear = s;        // 队尾指向新节点
    return OK;
}
int main()
{


    return 0;
}