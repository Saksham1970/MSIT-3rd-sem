#include <stdio.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

struct Node *dummyData()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    return (root);
}

void Inorder(struct Node *node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    printf("%d ,", node->data);
    Inorder(node->right);
}

void Preorder(struct Node *node)
{
    if (node == NULL)
        return;
    printf("%d ,", node->data);
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(struct Node *node)
{
    if (node == NULL)
        return;
    Postorder(node->left);
    Postorder(node->right);
    printf("%d ,", node->data);
}

char *binarytree_rep = "\t\t1\n\t2\t\t3\n4\t\t\t\t5";
