/*
代码：
typedef struct SqQueue{  
    int data[maxsize];  
    int front;//队首指针  
    int rear;//队尾指针  
}SqQueue;  
循环队列的状态：
（1）队空状态：
qu.front ==qu.rear  
（2）队满状态：
(qu->rear+1)%maxsize ==qu->front  
循环队列的操作：
（1）进队列：
qu->rear=(qu->rear+1)%maxsize;  
qu->data[qu->rear]=x;  
（2）出队列：
*y=qu->data[qu->front];  
qu->front=(qu->front+1)%maxsize;  
循环队列的实现：
*/
#include<stdio.h>  
#include<stdlib.h>  
#define maxsize 50  
typedef struct SqQueue{  
    int data[maxsize];  
    int front;//队首指针  
    int rear;//队尾指针  
}SqQueue;  
//创建循环队列  
SqQueue initQueue(){  
    SqQueue *sq=(SqQueue *)malloc(sizeof(SqQueue));  
    if(sq ==NULL){  
        return;  
    }  
    sq->rear=sq->front=0;  
    return *sq;  
}  
//判断循环队列是否为空  
int isEmpty(SqQueue qu){  
    return (qu.front ==qu.rear?1:0);  
}  
//元素进循环队列  
int enQueue(SqQueue *qu,int x){  
    if((qu->rear+1)%maxsize ==qu->front){  
        return 0;  
    }  
    qu->rear=(qu->rear+1)%maxsize;  
    qu->data[qu->rear]=x;  
    return 1;  
}  
//元素出循环队列  
int deQueue(SqQueue *qu,int *y){  
    if(qu->rear ==qu->front){  
        return 0;  
    }  
    *y=qu->data[qu->front];  
    qu->front=(qu->front+1)%maxsize;  
    return 1;  
}  
//打印循环队列  
int printQueue(SqQueue qu){  
    if(qu.rear ==qu.front){  
        return 0;  
    }  
    while(qu.rear !=qu.front){  
        qu.front=(qu.front+1)%maxsize;  
        printf("当前队列值=%d\n",qu.data[qu.front]);  
    }  
    return 1;  
}  
void main(){  
    int y=0;  
    SqQueue sq =initQueue();  
    enQueue(&sq,1);  
    enQueue(&sq,2);  
    enQueue(&sq,3);  
    enQueue(&sq,4);  
    deQueue(&sq,&y);  
    printQueue(sq);  
    printf("当前的front=%d\n",sq.front);  
    printf("当前的rear=%d\n",sq.rear);  
      
}  