//游戏规则：n 个参加者排成一个环，每次由主持向左轮手枪中装一颗子弹，并随机转动关上转轮，游戏从第一个人开始，轮流拿枪；中枪者退出赌桌，退出者的下一个人作为第一人开始下一轮游戏。直至最后剩余一个人，即为胜者。要求：模拟轮盘赌的游戏规则，找到游戏的最终胜者。
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum {false, true} bool;
typedef struct line {
    int no;
    struct line * next;
} line, *list;

// 按照赌徒人数，初始化循环链表
void initLine(list head, int n)
{
    head = (list)malloc(sizeof(line));
    head->next = NULL;
    head->no = 1;
    list l = head;
    for (int i = 1; i < n; i++)
    {
        list body = (list)malloc(sizeof(line));
        body->next = NULL;
        body->no = i + 1;
        l->next = body;
        l = l->next;
    }
    l->next = head;  // 将链表成环
}
// 输出链表中所有的结点信息
void display(list head)
{
    list temp = head;
    while (temp->next != head)
    {
        printf("%d", temp->no);
        temp = temp->next;
    }
    

}