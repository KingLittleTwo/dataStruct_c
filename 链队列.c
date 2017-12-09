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
 * -----》头结点。。。。。队尾。。。《----
 * 注意：为了避免当只有一个元素时，对头和队尾重合使处理变得麻烦，
 * 所以引入两个指针，front指针指向对头元素，rear指针指向队尾元素
 * 下一个位置，这样当front等于rear时，次队列不是还剩一个元素，而是
 * 空队列。
 * 
 * 当队列为空时，front和rear都指向头结点
 * front        rear
 * -----> 头结点 <------
 * 
 * 循环队列各个参数的含义
 * 1）队列的初始化
 * front和rear的值都是零，初始化时队列就是空的
 * 2）队列非空
 * front代表队列的第一个元素
 * rear代表了最后一个有效的下一个元素
 * 3）队列空
 * front和rear的值相等，但是不一定是零
 * 
 * 计算队列长度的公式
 * (rear - front + QueueSize) % QueueSize
 * 循环队列入队伪算法
 * rear = (rear + 1)%
 * 循环队列出队伪算法
 * front = (front +1)%
 * 
 * 判断循环队列是否已满
 * if ((rear + 1) % 队列长度） == front
 *      队列已满
 * else
 *      队列不满
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

/** 
 * @brief  
 * @note   初始化队列
 * @retval 
 */
LinkQueue initQueue()
{
    LinkQueue *lq = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (lq == NULL)
        printf("内存分配失败");
    lq->front = NULL;
    lq->rear = NULL;
    return *lq;
}
status isEmpty(LinkQueue *lq)
{
    if (lq->front == NULL || lq->rear == NULL)
        return FALSE;
    else
        return TRUE;
}
/** 
 * @brief  
 * @note   入队列操作
 * @param  *queue: 
 * @param  e: 
 * @retval 
 */
status EnQueue(LinkQueue *queue, int e)
{
    Queue p = (Queue)malloc(sizeof(QNode));
    if (!p) // 内存分配失败
        return FALSE;
    p->data = e;
    p->next = NULL;
    if (queue->rear == NULL)
        queue->front = queue->rear = p; // 如果第一次插入则设置头指针和尾指针都为p
    queue->rear->next = p;  
    queue->rear = p;        // 队尾指向新节点
    return OK;
}
/** 
 * @brief  
 * @note   元素出队列的操作
 * @param  *queue: 
 * @param  *e: 
 * @retval 
 */
status DeQueue(LinkQueue *queue, int *e)
{
    Queue p = queue->front;
    if (queue->front == NULL || queue->rear == NULL)
        return FALSE;
    if (queue->front == queue->rear)
        queue->front = queue->rear = NULL;
    else
        queue->front = queue->front->next;
    *e = p->data;
    free(p);
    return TRUE;
}
void traverse(LinkQueue *lq)
{
    if (lq->front == NULL || lq->rear == NULL)
        printf("队列为空");
    while (lq->front != NULL)
    {
        printf("%d\n", lq->front->data);
        lq->front = lq->front->next;
    }
}
int main()
{
    LinkQueue queue = initQueue();
    if (queue.front == NULL)
        printf("队列为空");
    printf("%d\n", queue.front->data);
    getchar();
    return 0;
}