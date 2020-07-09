//
// Created by jokermss on 2020/7/9.
//

#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct BTree {
    struct BTree *leftChild;
    ElemType data;
    struct BTree *rightChild;
} BT, *b_tree;

/**
 * 增加新节点
 * @brief insert_node
 * @param root
 * @param nodeValue
 * @return */
b_tree insert_node(b_tree root, ElemType nodeValue) {

    b_tree currentNode, parentNode, newNode;
    currentNode = root;
    newNode = (b_tree) malloc(sizeof(BT));
    if (newNode != NULL) {
        newNode->data = nodeValue;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
    }
    while (currentNode != NULL) {
        parentNode = currentNode;
        if (currentNode->data > nodeValue)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
        printf("find proper node\n");
    }
    if (parentNode->data > nodeValue)
        parentNode->leftChild = newNode;
    else
        parentNode->rightChild = newNode;
    return root;
}

/**
 * 创建二叉树
 * @brief create_BTree
 * @param nodeValue
 * @return */
b_tree create_BTree(b_tree root, int nodeValue) {
    if (root != NULL)
        root = insert_node(root, nodeValue);
    else {
        root = (b_tree) malloc(sizeof(BT));
        root->data = nodeValue;
        root->leftChild = NULL;
        root->rightChild = NULL;
    }
    return root;
}

/**
 * 前序遍历二叉树：先遍历根结点，再遍历左子树，最后才遍历右子树
 * @brief prePrint
 * @param root */
void prePrint(b_tree root) {
    if (root != NULL) {
        printf("%d", root->data);
        printf(" ");
        prePrint(root->leftChild);
        prePrint(root->rightChild);
    }
}

/**
 * 中序遍历二叉树：先遍历左子树，再遍历根结点，最后才遍历右子树
 * @brief midPrint
 * @param root */
void midPrint(b_tree root) {
    if (root != NULL) {
        midPrint(root->leftChild);
        printf("%d", root->data);
        printf(" ");
        midPrint(root->rightChild);
    }
}

/**
 * 后序遍历二叉树：先遍历左子树，再遍历右子树，最后遍历根结点
 * @brief lastPrint
 * @param root */
void lastPrint(b_tree root) {
    if (root != NULL) {
        lastPrint(root->leftChild);
        lastPrint(root->rightChild);
        printf("%d", root->data);
        printf(" ");
    }
}

void main() {

    printf("input binary tree node amount\n");
    int len, i;
    scanf("%d", &len);
    int arr[len + 1];
    printf("input node values\n");
    for (i = 1; i <= len; i++) {
        scanf("%d", &arr[i]);
    }
    b_tree root;
    root = (b_tree) malloc(sizeof(BT));
    if (root != NULL) {
        //要把 root->leftChild root->rightChild初始化为NULL，不然下面的insert_node()会死循环
        root->leftChild = NULL;
        root->rightChild = NULL;
        root->data = arr[1];
        for (i = 2; i <= len; i++)
            root = create_BTree(root, arr[i]);
    }
    prePrint(root);
    //midPrint(root);
    //lastPrint(root);
}