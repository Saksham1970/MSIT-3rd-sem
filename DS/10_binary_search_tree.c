#include <stdio.h>

struct Automobile
{
    char *type;
    char *company;
    int year_of_make;
};

struct Node
{
    struct Automobile automobile;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(struct Automobile automobile)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->automobile = automobile;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

void insert(struct Node **root, struct Node *node)
{

    if (*root == NULL)
    {
        *root = node;
        return;
    }

    if (node->automobile.year_of_make > (*root)->automobile.year_of_make)
        insert(&((*root)->right), node);

    else
        insert(&((*root)->left), node);
}

struct Node *largest(struct Node *root)
{

    int largest_yom = root->automobile.year_of_make;
    struct Node *largest_node = root;

    if (root->left != NULL)
    {
        struct Node *largest_left = largest(root->left);
        if (largest_yom < largest_left->automobile.year_of_make)
        {
            largest_yom = largest_left->automobile.year_of_make;
            largest_node = largest_left;
        }
    }
    if (root->right != NULL)
    {
        struct Node *largest_right = largest(root->right);
        if (largest_yom < largest_right->automobile.year_of_make)
        {
            largest_yom = largest_right->automobile.year_of_make;
            largest_node = largest_right;
        }
    }
    return largest_node;
}

int delete (struct Node **root, int year_of_make)
{

    if (*root == NULL)
    {
        return 0;
    }

    if (year_of_make > (*root)->automobile.year_of_make)
        return delete (&((*root)->right), year_of_make);

    else if (year_of_make < (*root)->automobile.year_of_make)
        return delete (&((*root)->left), year_of_make);

    else
    {
        if ((*root)->left == NULL)
        {
            struct Node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return 1;
        }
        else if ((*root)->right == NULL)
        {
            struct Node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return 1;
        }
        else
        {
            struct Node *largest_left = largest((*root)->left);
            (*root)->automobile = largest_left->automobile;
            delete (&((*root)->left), largest_left->automobile.year_of_make);
        }
    }
}

struct Node *dummyData()
{
    struct Node *root = NULL;
    struct Automobile a1, a2, a3;

    a1.company = "BMW";
    a1.type = "1 Series";
    a1.year_of_make = 2013;

    a2.company = "Audi";
    a2.type = "100";
    a2.year_of_make = 1994;

    a3.company = "FIAT";
    a3.type = "124 Spider";
    a3.year_of_make = 2019;

    insert(&root, newNode(a1));
    insert(&root, newNode(a2));
    insert(&root, newNode(a3));

    return root;
}

void Inorder(struct Node *node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    printf("Company: %s, Type: %s, Year:%d\n", node->automobile.company, node->automobile.type, node->automobile.year_of_make);
    Inorder(node->right);
}

void Preorder(struct Node *node)
{
    if (node == NULL)
        return;
    printf("Company: %s, Type: %s, Year:%d\n", node->automobile.company, node->automobile.type, node->automobile.year_of_make);
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(struct Node *node)
{
    if (node == NULL)
        return;
    Postorder(node->left);
    Postorder(node->right);
    printf("Company: %s, Type: %s, Year:%d\n", node->automobile.company, node->automobile.type, node->automobile.year_of_make);
}
