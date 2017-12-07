#include <stdio.h>
#include <stdlib.h>
#include "header.h"
/*
链表的优缺点：
    优点：
        空间没有限制
        插入删除元素很快
     缺点：
        存取速度很慢。
定义：
    n个节点离散分配（在内存中不是连续存储）
    彼此通过指针相连
    每个节点只有一个前驱节点，每个节点只有一个后续节点
    首节点没有前驱节点，尾节点没有后续节点。
            首节点：
                    第一个有效节点
            尾节点：
                    最后一个有效节点
            头节点：
                    头结点的数据类型和首节点的类型一样
                    没有存放有效数据，最最前面的，是在
                    首节点之前的，主要是为了方便对链表
                    的操作。
            头指针：（指向头）
                    指向头节点的指针变量
            尾指针：
                    指向尾节点的指针
                           
（头结点有可能很大，占的内存可能大，假设我想造一个函数
输出所有链表的值，那你如果不用头指针类型做形参，那由于
不同链表的头节点不一样大小，这样就没办法找出形参）
**确定一个链表需要几个参数：（或者说如果期望一个函数对链表进行操作
我们至少需要接收链表的那些信息？？？）
只需要一个参数:头指针，因为通过它我们可以推出
链表的所有信息。
（链表的程序最好一定要自己敲出来）
 
链表的分类：单链表
    双链表：
        每一个节点有两个指针域

    循环链表
        能通过任何一个节点找到其他所有的节点
单链表伪算法：1.插入节点：
在p指向的节点后面插入一个被q指向的节点：
 
P存放的是指向的节点的地址，q也是。next指针存放的是下一个元素的地址。
 
q->next=p->next;p->next=q;
也可以
r=p->next; p->next=q;q->next=r;
 
删除p后面的节点
 
P->next=p->next->next 会造成内存泄露，无法找到要删除的节点，无法释放内存。
正确做法：临时定义一个指针r 存放要删除节点的地址
r=p->next;
p->next=p->next->next;
free(r);//释放所指节点占用的内存

*/

// 线性表：由同类型数据元素构成有序序列的线性结构

typedef struct Node
{
    int data;          // 数据域
    struct Node *next; // 指针域
} Node, *PNode;
/** 
 * @brief  
 * @note   创建链表
 * @retval 
 */
PNode createList()
{
    int len, i;
    printf("请输入链表的长度：len=\n");
    scanf("%d", &len);
    PNode PHead = malloc(sizeof(Node));
    PHead->next = NULL;
    PNode PTail = PHead; // PTail 的指针永远指向NULL
    for (i = 0; i < len; i++)
    {
        int val;
        printf("请输入第%d个元素的值：", i + 1);
        scanf("%d", &val);
        PNode PNew = malloc(sizeof(Node));
        PNew->data = val;
        PNew->next = NULL;
        PTail->next = PNew;
        PTail = PNew;
    }
    return PHead;
}
/** 
 * @brief  
 * @note            对链表进行遍历  
 * @param  PHead: 
 * @retval None
 */
void traverse(PNode PHead)
{
    PNode p = PHead->next;
    while (p != NULL)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}
/** 
 * @brief  
 * @note   判断链表是否为空
 * @param  PHead: 
 * @retval 
 */
status isEmpty(PNode PHead)
{
    if (PHead->next == NULL)
        return TRUE;
    else
        return FALSE;
}

/** 
 * @brief  
 * @note            向链表中插入元素   
 * @param  PHead: 
 * @param  val: 
 * @param  pos: 
 * @retval 
 */
status insertList(PNode PHead, int val, int pos)
{
    int i = 0;
    PNode p = PHead;
    // 第pos个位置，在i<pos-1时跳出循环此时i就是要插入的位置
    while (p != NULL && i < pos - 1)
    {
        i++;
        p = p->next;
    }
    // 判断位置是否合法
    // 如果插入位置过大，p=null, 如果插入的位置是0或者负数，那么i>pos-1
    if (i > pos - 1 || p == NULL)
    {
        printf("插入位置不合法\n");
        return FALSE;
    }

    PNode PNew = malloc(sizeof(PNode));
    PNew->data = val;
    PNode tmp = p->next;
    p->next = PNew;
    PNew->next = tmp;
    return TRUE;
}

/** 
 * @brief  
 * @note   获取链表的长度
 * @param  PHead: 
 * @retval 
 */
int listLength(PNode PHead)
{
    int num = 0;
    PNode p = PHead->next;
    while (p != NULL)
    {
        num++;
        p = p->next;
    }
    return num;
}

status deleteNode(PNode PHead, int pos)
{
    int i = 0;
    PNode p = PHead;
    //PHead 不能为最后一个结点
    while (p->next != NULL && i < pos - 1)
    {
        p = p->next;
        i++;
    }
    if (i > pos - 1 || p->next == NULL)
    {
        printf("删除位置不合法");
        return FALSE;
    }
    PNode tmp = p->next;
    p->next = tmp->next;
    free(tmp);
    return OK;
}

int main()
{
    PNode p = createList();
    printf("第一次遍历： ");
    traverse(p);

    status a = insertList(p, 666, 1);
    printf("状态为：%d\n", a);
    printf("第二次遍历： ");
    traverse(p);
    deleteNode(p, 3);
    printf("第三次遍历： ");
    traverse(p);
    // int val;
    // printf("请输入：\n");
    // scanf("%d", &val);
    // printf("输入的数字为：%d\n", val);
    return 0;
}
