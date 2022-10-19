#include <stdio.h> // Header files
#include <stdlib.h>

// Node struct of the binary tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Prototyping the functions
void Inorder(struct Node *);
void Preorder(struct Node *);
void Postorder(struct Node *);
struct Node *dummyData();

// Driver Code
int main()
{

    // The Binary tree representation as ASCII art
    char binarytree_rep[40] = "    1\n   / \\\n  2   3\n / \\\n4    5";
    printf("Binary Tree:\n%s", binarytree_rep);

    // Gets the Dummy binary tree to perform operations on
    struct Node *root = dummyData();

    // Printing the Inorder traversal of binary tree
    printf("\nInorder traversal:\n");
    Inorder(root);

    // Printing the Preorder traversal of binary tree
    printf("\nPreorder traversal:\n");
    Preorder(root);

    // Printing the Postorder traversal of binary tree
    printf("\nPostorder traversal:\n");
    Postorder(root);

    return 0;
}

struct Node *newNode(int data)
{
    // Function to create a new node with the data
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("Overflow");
        return node;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct Node *dummyData()
{
    // Creating a dummy tree to do our operations on

    // Linking our binary tree
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    return root;
}

void Inorder(struct Node *node)
{
    // Function to traverse through the binary tree in Inorder

    // If tree is empty
    if (node == NULL)
        return;

    // Inorder traversing through left subtree and then
    // printing the root value
    // and then Inorder traversing through right subtree
    Inorder(node->left);
    printf("%d ,", node->data);
    Inorder(node->right);
}

void Preorder(struct Node *node)
{
    // Function to traverse through the binary tree in Preorder

    // If tree is empty
    if (node == NULL)
        return;

    // printing the root value then
    // Inorder traversing through left subtree and then
    // Inorder traversing through right subtree
    printf("%d ,", node->data);
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(struct Node *node)
{
    // Function to traverse through the binary tree in Postorder

    // If tree is empty
    if (node == NULL)
        return;

    // Inorder traversing through left subtree and then
    // Inorder traversing through right subtree and then
    // printing the root value
    Postorder(node->left);
    Postorder(node->right);
    printf("%d ,", node->data);
}
