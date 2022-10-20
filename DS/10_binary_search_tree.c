#include <stdio.h> // Header files
#include <stdlib.h>

// Struct Automobile to store data about automobile
struct Automobile
{
    char const *type;
    char const *company;
    int year_of_make;
};

// Node struct of the BST
struct Node
{
    struct Automobile automobile;
    struct Node *left;
    struct Node *right;
};

// Prototyping the functions
struct Node *dummyData();

struct Node *newNode(struct Automobile);
void insert(struct Node **, struct Node *);

struct Node *largest(struct Node *);
int delete(struct Node **, int);

void Inorder(struct Node *);
void Preorder(struct Node *);
void Postorder(struct Node *);

// Driver code
int main()
{
    // Gets a dummy BST for us to perform operations on
    struct Node *root = dummyData();
    printf("Created BST:\n");
    Preorder(root); // Displaying the BST using Preorder traversal

    // Creating an automobile data and inserting it into the BST
    struct Automobile automobile = {"Mercedes-Benz", "300 CE", 1993};
    insert(&root, newNode(automobile));
    printf("\nBST After inserting a Node:\n");
    Preorder(root);

    // Removing the car with year of make as 1994
    delete(&root, 1994);
    printf("\nBST After Removing a Car with year of make as 1994:\n");
    Preorder(root);

    // Printing the Inorder traversal of BST
    printf("\nInorder traversal:\n");
    Inorder(root);

    // Printing the Preorder traversal of BST
    printf("\nPreorder traversal:\n");
    Preorder(root);

    // Printing the Postorder traversal of BST
    printf("\nPostorder traversal:\n");
    Postorder(root);

    return 0;
}

struct Node *newNode(struct Automobile automobile)
{
    // Function to create a new node with the automobile data
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("Overflow");
        return node;
    }
    node->automobile = automobile;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(struct Node **root, struct Node *node)
{
    // Function to insert a node into the BST
    // Inserting on the basis of year of make

    // If tree empty
    if (*root == NULL)
    {
        *root = node;
        return;
    }

    // If year of make of node greater than the root's year of make
    if (node->automobile.year_of_make > (*root)->automobile.year_of_make)
        insert(&((*root)->right), node); // Insert in right subtree

    else
        insert(&((*root)->left), node); // Insert in left subtree
}

struct Node *largest(struct Node *root)
{
    // Function for finding the largest node in the tree
    // Used in the removing node from a BST function

    // Checking the largest on the basis of year of make
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

    // Returning the largest node
    return largest_node;
}

int delete(struct Node **root, int year_of_make)
{
    // Function to delete a node from the BST
    // Deleting on the basis of year of make
    // Returns 0 if deletion failed
    // Returns 1 if deletion successful

    // If tree empty
    if (*root == NULL)
        return 0;

    // If year of make of node greater than the root's year of make
    if (year_of_make > (*root)->automobile.year_of_make)
        return delete(&((*root)->right), year_of_make); // deletion in the right subtree

    // If year of make of node leseer than the root's year of make
    else if (year_of_make < (*root)->automobile.year_of_make)
        return delete(&((*root)->left), year_of_make); // deletion in the left subtree

    else                           // If year of make of node is equal to the root's year of make
    {                              // root is the node to be deleted
        if ((*root)->left == NULL) // if left subtree empty
        {
            // Set right subtree as root
            struct Node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return 1;
        }
        else if ((*root)->right == NULL) // if right subtree empty
        {
            // Set left subtree as root
            struct Node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return 1;
        }
        else // Both subtrees not empty
        {
            // Putting the largest node from left subtree as root
            struct Node *largest_left = largest((*root)->left);
            (*root)->automobile = largest_left->automobile;
            // Deleting the largest node in the left subtree
            return delete(&((*root)->left), largest_left->automobile.year_of_make);
        }
    }
}

struct Node *dummyData()
{
    // Creating a dummy tree to do our operations on

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

    // Inserting the automobiles into the BST
    insert(&root, newNode(a1));
    insert(&root, newNode(a2));
    insert(&root, newNode(a3));

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
    printf("Company: %s, Type: %s, Year:%d\n", node->automobile.company, node->automobile.type, node->automobile.year_of_make);
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
    printf("Company: %s, Type: %s, Year:%d\n", node->automobile.company, node->automobile.type, node->automobile.year_of_make);
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(struct Node *node)
{
    // Function to traverse through the binary tree in Preorder

    // If tree is empty
    if (node == NULL)
        return;

    // Inorder traversing through left subtree and then
    // Inorder traversing through right subtree and then
    // printing the root value
    Postorder(node->left);
    Postorder(node->right);
    printf("Company: %s, Type: %s, Year:%d\n", node->automobile.company, node->automobile.type, node->automobile.year_of_make);
}
