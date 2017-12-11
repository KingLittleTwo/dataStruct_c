#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
 * 二叉查找树
 * 定义：又被称为二叉搜索树，设x为二叉树中的一个结点，x节点包含关键字key，
 * 节点x 的key值记为key[x].如果y是x的左子树中的一个节点，则key[y] <= key[x]; 
 * 如果y是x的右子树的一个结点，则key[y] >= key[x]。
 * 
 * 注意：
 * - 若任一节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值
 * - 任意节点的右子树不空，则右子树上所有的值均大于它的根节点的值
 * - 任意节点的左右子树也分别为二叉查找树
 * - 没有键值相等的节点(no duplicate nodes)
 * 
 * 节点的前驱和后继
 * 节点的前驱：是该节点的左子树中的最大节点。
 * 节点的后继：是该节点的右子树中的最小节点。
 */
typedef struct BSTreeNode
{
    int key;                   // 关键字，用来对二叉查找树的节点进行排序的
    struct BSTreeNode *left;   // 左孩子
    struct BSTreeNode *right;  // 右孩子
    struct BSTreeNode *parent; // 父节点
} Node, *BSTree;

BSTree createBstreeNode(int key, BSTree parent, BSTree left, BSTree right)
{
    BSTree p;
    if ((p = (BSTree)malloc(sizeof(Node))) == NULL)
        return NULL;
    p->key = key;
    p->left = left;
    p->right = right;
    p->parent = parent;

    return p;
}
/** 
 * @brief  
 * @note   前序遍历二叉树
 * @param  tree: 
 * @retval None
 */
void preOrderTraverse(BSTree tree)
{
    if (tree != NULL)
    {
        printf("%d\t", tree->key);
        preOrderTraverse(tree->left);
        preOrderTraverse(tree->right);
    }
}
/** 
 * @brief  
 * @note   中序遍历二叉树
 * @param  tree: 
 * @retval None
 */
void InOrderTraverse(BSTree tree)
{
    if (tree != NULL)
    {
        InOrderTraverse(tree->left);
        printf("%d\t", tree->key);
        InOrderTraverse(tree->right);
    }
}
/** 
 * @brief  
 * @note   后序遍历二叉树
 * @param  tree: 
 * @retval None
 */
void postOrderTraverse(BSTree tree)
{
    if (tree != NULL)
    {
        postOrderTraverse(tree->left);
        postOrderTraverse(tree->right);
        printf("%d\t", tree->key);
    }
}
/** 
 * @brief  
 * @note   递归版本查找
 * @param  tree: 
 * @param  key: 
 * @retval 
 */
BSTree searchBstree(BSTree tree, int key)
{
    if (tree == NULL || tree->key == key)
        return tree;
    if (key < tree->key)
        return searchBstree(tree->left, key);
    else
        return searchBstree(tree->right, key);
}
/** 
 * @brief  
 * @note   非递归版本查找
 * @param  tree: 
 * @param  key: 
 * @retval 
 */
BSTree interativeSearchBstree(BSTree tree, int key)
{
    while ((tree != NULL) && (tree->key != key))
    {
        if (key < tree->key)
            tree = tree->legt;
        else
            tree = tree->right;
    }
    return tree;
}

/** 
 * @brief  
 * @note   查找最大值
 * @param  tree: 
 * @retval 
 */
BSTree findMax(BSTree tree)
{
    if (tree == NULL)
        return NULL;
    while (tree->right != NULL)
        tree = tree->right;
    return tree;
}
/** 
 * @brief  
 * @note   查找最小值
 * @param  tree: 
 * @retval 
 */
BSTree findMin(BSTree tree)
{
    if (tree == NULL)
        return NULL;
    while (tree->left != NULL)
        tree = tree->left;
    return tree;
}

/** 
 * @brief  
 * @note   找到前驱节点
 * @param  tree: 
 * @retval 
 */
BSTree findPreNode(BSTree tree)
{
    // 如果tree存在左孩子，则tree的前驱节点为“其左孩子为根的子树的最大节点”
    if (tree->left != NULL)
        return findMax(tree->left);
    // 如果tree没有左孩子，则tree有以下两种可能：
    // 1）tree是一个右孩子，则tree的前驱节点为“它的父节点”
    // 2）tree是一个左孩子，则查找tree的最低的父节点，并且该父节点要具有右孩子，找到的这个最低的父节点就是tree的前驱节点
    BSTree y = tree->parent;
    while ((y != NULL) && (tree == y->left))
    {
        tree = y;
        y = y->parent;
    }
    return y;
}

/** 
 * @brief  
 * @note   找到后继节点
 * @param  tree: 
 * @retval 
 */
BSTree findPostNode(BSTree tree)
{
    // 如果tree存在右孩子，则tree的后继节点为“其右孩子为根的子树的最小节点”
    if (tree->right != NULL)
        return findMin(tree->right);
    // 如果tree没有右孩子，则tree有以下两种可能：
    // 1）tree是一个左孩子，则tree的后继节点为“它的父节点”
    // 2）tree是一个右孩子，则查找tree的最低的父节点，并且该父节点要具有左孩子，找到的这个最低的父节点就是tree的后继节点
    BSTree y = tree->parent;
    while ((y != NULL) && (tree == y->right))
    {
        tree = y;
        y = y->parent;
    }
    return y;
}
/** 
 * @brief  
 * @note  内部函数，它的作用是：将结点(z)插入到二叉树(tree)中，并返回插入节点后的根节点 
 * @param  tree: 
 * @param  *z: 
 * @retval 
 */
static BSTree _insertBSTree(BSTree tree, Node *z)
{
    Node *y = NULL;
    Node *x = tree;
    // 查找z的插入位置
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else if (z->key > x->key)
            x = x->right;
        else
        {
            free(z); // 释放之前分配的内存
            return tree;
        }
    }
    z->parent = y;
    if (y == NULL)
        tree = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
    return tree;
}

/** 
 * @brief  
 * @note   对外接口，它的作用是：在树中新增节点，key是节点的值；并返回插入节点后的根节点
 * @param  tree: 
 * @param  key: 
 * @retval 
 */
BSTree insertBSTree(BSTree tree, int key)
{
    BSTree z;   // 新建节点
    // 如果新建节点失败，则返回
    if ((z = createBstreeNode(key, NULL, NULL, NULL)) == NULL)
        return tree;
    return _insertBSTree(tree, z);
}

/** 
 * @brief  
 * @note   内部函数，它的作用是：删除二叉树(tree)中的节点(z)，并返回删除节点后的根节点
 * @param  tree: 
 * @param  z: 
 * @retval 
 */
static BSTree _deleteBstreeNode(BSTree tree, BSTree z)
{
    BSTree x = NULL;
    BSTree y = NULL;

    if ((z->left == NULL) || (z->right) == NULL)
        y = z;
    else
        y = findPostNode(z);
    
    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;
    
    if (x != NULL)
        x->parent = y->parent;

    if (y->parent == NULL)
        tree = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    
    if (y != z)
        z->key = y->key;
    
    if (y != NULL)
        free(y);
    
    return tree;
}

/** 
 * @brief  
 * @note   对外接口，它的作用是：在树中查找键值为key的节点，找到的话就删除该节点；并返回删除节点后的根节点
 * @param  tree: 
 * @param  key: 
 * @retval 
 */
BSTree deleteBstreeNode(BSTree tree, int key)
{
    BSTree z, node;
    if ((z = searchBstree(tree, key)) != NULL)
        tree = _deleteBstreeNode(tree, z);
    return tree;
}

/** 
 * @brief  
 * print_bstree(tree, key, direction)的作用是打印整颗二叉树(tree)。其中，tree是二叉树节点，key是二叉树的键值，而direction表示该节点的类型：
 * direction为 0，表示该节点是根节点;
 * direction为-1，表示该节点是它的父结点的左孩子;
 * direction为 1，表示该节点是它的父结点的右孩子。
 */ 

void print_bstree(BSTree tree, int key, int direction)
{
    if(tree != NULL)
    {
        if(direction==0)    // tree是根节点
            printf("%2d is root\n", tree->key);
        else                // tree是分支节点
            printf("%2d is %2d's %6s child\n", tree->key, key, direction==1?"right" : "left");

        print_bstree(tree->left, tree->key, -1);
        print_bstree(tree->right,tree->key,  1);
    }
}

/** 
 * @brief  
 * @note   销毁二叉树
 * @param  tree: 
 * @retval None
 */
void destroy_bstree(BSTree tree)
{
    if (tree==NULL)
        return ;

    if (tree->left != NULL)
        destroy_bstree(tree->left);
    if (tree->right != NULL)
        destroy_bstree(tree->right);

    free(tree);
}