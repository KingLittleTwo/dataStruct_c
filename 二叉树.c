#include <stdio.h>
#include <stdlib.h>
#include "header.h"

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}Tree, *PtrToNode;

PtrToNode initTree()
{
    PtrToNode tree;
    int a;
    printf("输入根结点：（0表示空树)\n");
    scanf("%d", &a);
    if (a == 0)
    {
        printf("这是空树！");
        exit(0);
    }
    tree = (PtrToNode)malloc(sizeof(Tree));
    if (tree == NULL)
    {
        printf("分配内存失败");
        return NULL;
    }
    else
    {
        tree->data = a;
        tree->left = NULL;
        tree->right = NULL;
    }
    return tree;
}

/**
 * 在tree中找到x的位置 
 */
PtrToNode find(PtrToNode tree, int x)
{
    if (tree == NULL)
        return NULL;
    if (x < tree->data)
        return find(tree->left, x);
    else if (x > tree->data)
        return find(tree->right, x);
    else
        return tree;
}
PtrToNode findMin(PtrToNode tree)
{
    if (tree == NULL)
        return NULL;
    else if (tree->left == NULL)
        return tree;
    else
        return findMin(tree->left);
}
PtrToNode findMax(PtrToNode tree)
{
    if (tree != NULL)
    {
        while(tree->right != NULL)
            tree = tree->right;
    }
    return tree;
}

PtrToNode insert(PtrToNode tree, int x)
{
    if (tree == NULL)
    {
        tree = (PtrToNode)malloc(sizeof(Tree));
        if (tree == NULL)
        {
            printf("内存已满创建失败");
            return ERROR;
        } else {
            tree->data = x;
            tree->left = tree->right = NULL;
        }
    }
    else if (x < tree->data)
    {  
        tree->left = insert(tree->left, x);
    }
    else if (x > tree->data)
    {
        tree->right = insert(tree->right, x);            
    }
    // else x is in the tree already; we`ll do nothing
    return tree;
}
/**
 * 前序递归遍历
 */ 
void PreOrderTraverse(PtrToNode tree)
{
    // 注意跳出条件
    if (tree != NULL)
    {
        printf("%d\t", tree->data);
        PreOrderTraverse(tree->left);
        PreOrderTraverse(tree->right);
    }
}
/**
 * 中序递归遍历
 */ 
void InOrderTraverse(PtrToNode tree)
{
    // 注意跳出条件
    if (tree != NULL)
    {
        InOrderTraverse(tree->left);
        printf("%d\t", tree->data);        
        InOrderTraverse(tree->right);
    }
}
/**
 * 后序递归遍历
 */ 
void PostOrderTraverse(PtrToNode tree)
{
    // 注意跳出条件
    if (tree != NULL)
    {
        PostOrderTraverse(tree->left);
        PostOrderTraverse(tree->right);
        printf("%d\t", tree->data);
    }
}

//前序非递归遍历
// int NoPreOrderTraverse(PtrToNode t)
// {
//     SqStack s;
//     InitStack(&s);
 
//     PtrToNode tmp = t;
//     if(tmp == NULL)
//     {
//         fprintf(stdout, "the tree is null.\n");
//         return ERROR;
//     }
//    //现将左子树压入栈，当到叶子结点后，出栈，获取右子树，然后在压入右子树的左子树。
//   //顺序不能变
//     while((tmp != NULL) || (IsEmpty(&s) != 1)) 
//     {
//         while(tmp != NULL)
//         {
//             Push(&s, tmp);
//             printf("%c ", tmp->data);
//             tmp = tmp->left;
//         }
//         if(IsEmpty(&s) != 1)
//         {
//             Pop(&s, &tmp);
//             tmp = tmp->right;
//         }
//     }
     
//     return OK;
// }

int main()
{
    PtrToNode tree;
    tree = initTree();
    tree = insert(tree, 1);
    tree = insert(tree, 2);
    tree = insert(tree, 3);
    tree = insert(tree, 4);
    tree = insert(tree, 5);
    tree = insert(tree, 6);
    PreOrderTraverse(tree);
    printf("\n");
    
    InOrderTraverse(tree);
    printf("\n");

    PostOrderTraverse(tree);

    printf("\n");
    
    
    return 0;
}