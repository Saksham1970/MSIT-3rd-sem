#include <stdio.h> // Header files
#include <stdlib.h>

// For Queue
struct Node
{
    struct graphVertex *vertex;
    struct Node *next;
};
struct Node *bottom = NULL;
struct Node *top = NULL;

// Struct to store the other end of the vertex's edge
struct graphArc
{

    struct graphVertex *destination; // The other end's vertex
    struct graphArc *nextArc;        // The next edge's arc
};

// The Vertex element whose linked list represents the graph
struct graphVertex
{

    struct graphVertex *nextVertex; // Next vertex in the list
    int data;                       // Data of the vertex
    int processed;                  // If the data has been read already( For cycle graphs )
    struct graphArc *firstArc;      // First edge's arc
};

// Prototyping the functionis
void depth_first_traversal(struct graphVertex *);
void breadth_first_traversal(struct graphVertex *);
struct graphVertex *dummyGraph();

// Driver code
int main()
{

    // The Graph representation as ASCII art
    char graph_representation[25] = "0 - 1\n| / | \\\n4 - 3 - 2";
    printf("Graph:\n%s", graph_representation);

    // Gets the Dummy Graph to perform operations on
    struct graphVertex *vertex = dummyGraph();

    // Printing the DFS traversal of the graph
    printf("\nDFS traversal:\n");
    depth_first_traversal(vertex);

    // Printing the BFS traversal of the graph
    printf("\nBFS traversal:\n");
    breadth_first_traversal(vertex);

    return 0;
}

// Insert element into queue
void insert_queue(struct graphVertex *vertex)
{
    // Function to insert an element into the queue
    // Allocating memory to the new node in the queue
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Overflow
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }

    // Assigning values to the node
    newNode->vertex = vertex;
    newNode->next = NULL;

    // replacing the top
    if (bottom == NULL)
        bottom = top = newNode;
    else
    {
        top->next = newNode;
        top = newNode;
    }
}

struct graphVertex *remove_queue()
{
    // Function to delete and return element from queue
    // Checks if elements present
    // Returns NULL if underflow

    if (bottom == NULL)
    {
        printf("Underflow\n");
        return NULL;
    }
    else
    {
        struct Node *temp = bottom;
        struct graphVertex *element = bottom->vertex; // to store data of top node
        bottom = bottom->next;
        if (bottom == NULL)
            top = bottom;
        free(temp); // deleting the node
        return element;
    }
}

struct graphVertex *addGraphEdge(struct graphVertex *vertex, int a, int b)
{

    // Function to add 2 vertexes which form an edge into the graph

    // Vertexes with data a and b
    struct graphVertex *a_vertex = NULL, *b_vertex = NULL;

    // Loop variable ptr to loop through the graph
    struct graphVertex *ptr = vertex;

    // If not empty graph check if a vertex and b vertex exist
    if (ptr != NULL)
    {
        while (1)
        {
            if (ptr->data == a)
                a_vertex = ptr;
            if (ptr->data == b)
                b_vertex = ptr;
            if (a_vertex != NULL && b_vertex != NULL)
                break;

            if (ptr->nextVertex == NULL)
                break;

            ptr = ptr->nextVertex;
        }
    }

    // Ptr is pointing at the end of the list
    // a_vertex is the vertex in graph which has data a or NULL if doesnt exit
    // b_vertex is the vertex in graph which has data b or NULL if doesnt exit

    // If a_vertex not in list
    if (a_vertex == NULL)
    {
        // Create a_vertex
        struct graphVertex *a_temp = (struct graphVertex *)malloc(sizeof(struct graphVertex));

        if (a_temp == NULL) // Check Overflow
        {
            printf("Overflow\n");
            return vertex;
        }

        // Assigning value to a_vertex (temp)
        a_temp->nextVertex = NULL;
        a_temp->data = a;
        a_temp->processed = 64;
        a_temp->firstArc = NULL;

        // Assigning temp to the main
        a_vertex = a_temp;

        // If list is empty
        if (ptr == NULL)
            ptr = a_vertex;

        // Else append at the end
        else
        {
            ptr->nextVertex = a_vertex;
            ptr = ptr->nextVertex;
        }
    }

    // If b_vertex not in list
    if (b_vertex == NULL)
    {
        // Create b_vertex
        struct graphVertex *b_temp = (struct graphVertex *)malloc(sizeof(struct graphVertex));

        if (b_temp == NULL) // Check Overflow
        {
            printf("Overflow\n");
            return vertex;
        }

        // Assigning value to b_vertex(temp)
        b_temp->nextVertex = NULL;
        b_temp->data = b;
        b_temp->processed = 32;
        b_temp->firstArc = NULL;

        // Assigning temp to the main
        b_vertex = b_temp;

        // Appending at the end
        ptr->nextVertex = b_vertex;
        ptr = ptr->nextVertex;
    }

    // Arcs with data a and b
    // a_arc is in b_vertex and b_arc is in a_vertex
    struct graphArc *a_arc = NULL, *b_arc = NULL;

    // Loop variables to loop through the edges of vertices
    struct graphArc *aptr = a_vertex->firstArc, *bptr = b_vertex->firstArc;

    // If not empty check if b_arc exists in a_vertex
    while (aptr != NULL)
    {
        if (aptr->destination == b_vertex)
        {
            b_arc = aptr;
            break;
        }
        if (aptr->nextArc == NULL)
            break;

        aptr = aptr->nextArc;
    }

    // If not empty check if a_arc exists in b_vertex
    while (bptr != NULL)
    {
        if (bptr->destination == a_vertex)
        {
            a_arc = bptr;
            break;
        }
        if (bptr->nextArc == NULL)
            break;

        bptr = bptr->nextArc;
    }

    // aptr is pointing at the end of the edges of a_vertex
    // bptr is pointing at the end of the edges of b_vertex
    // a_arc is the arc in b_vertex which has data a or NULL if doesnt exit
    // b_arc is the arc in a_vertex which has data b or NULL if doesnt exit

    // If a_arc not in edges
    if (a_arc == NULL)
    {
        // Create a_arc
        struct graphArc *a_arc_temp = (struct graphArc *)malloc(sizeof(struct graphArc));

        if (a_arc_temp == NULL) // Check Overflow
        {
            printf("Overflow\n");
            return vertex;
        }

        // Assigning value to a_arc (temp)
        a_arc_temp->nextArc = NULL;
        a_arc_temp->destination = a_vertex;

        // Assigning temp to the main
        a_arc = a_arc_temp;

        // If no edges
        if (bptr == NULL)
            b_vertex->firstArc = a_arc_temp;

        // Else append at the end
        else
            bptr->nextArc = a_arc_temp;
    }

    if (b_arc == NULL)
    {
        // Create b_arc
        struct graphArc *b_arc_temp = (struct graphArc *)malloc(sizeof(struct graphArc));

        if (b_arc_temp == NULL) // Check Overflow
        {
            printf("Overflow\n");
            return vertex;
        }

        // Assigning value to b_arc (temp)
        b_arc_temp->nextArc = NULL;
        b_arc_temp->destination = b_vertex;

        // Assigning temp to the main
        b_arc = b_arc_temp;

        // If no edges
        if (aptr == NULL)
            a_vertex->firstArc = b_arc_temp;

        // Else append at the end
        else
            aptr->nextArc = b_arc_temp;
    }

    // If graph is empty
    if (vertex == NULL)
        return a_vertex;

    // Else return original list
    else
        return vertex;
}

struct graphVertex *dummyGraph()
{
    // This function creates Dummy data for us to work on

    struct graphVertex *vertex = addGraphEdge(NULL, 0, 1);
    addGraphEdge(vertex, 0, 4);
    addGraphEdge(vertex, 1, 3);
    addGraphEdge(vertex, 1, 4);
    addGraphEdge(vertex, 4, 3);
    addGraphEdge(vertex, 3, 2);
    addGraphEdge(vertex, 1, 2);

    // Returns the graph
    return vertex;
}

void depth_first_recursion(struct graphVertex *vertex)
{
    // If already printed return
    if (vertex->processed == 1)
        return;

    // Else process
    printf("%d, ", vertex->data);
    vertex->processed = 1;

    // Loop through the edges of the vertex
    struct graphArc *ptr = vertex->firstArc;
    while (ptr != NULL)
    {
        // Recursively process the nodes by looping through arcs
        depth_first_recursion(ptr->destination);
        ptr = ptr->nextArc;
    }
}

void depth_first_traversal(struct graphVertex *vertex)
{
    // This function is to traverse through the graph using DFS
    // If graph is empty, return
    if (vertex == NULL)
        return;

    // Loop through the vertices and set them as unprocessed
    struct graphVertex *ptr = vertex;
    while (ptr != NULL)
    {
        ptr->processed = 0;
        ptr = ptr->nextVertex;
    }

    // Use recursion to proecess the nodes
    depth_first_recursion(vertex);
}

void breadth_first_traversal(struct graphVertex *vertex)
{
    // This function is to traverse through the graph using DFS
    // If graph is empty, return
    if (vertex == NULL)
        return;

    // Loop through the vertices and set them as unprocessed
    struct graphVertex *ptr = vertex;
    while (ptr != NULL)
    {
        ptr->processed = 0;
        ptr = ptr->nextVertex;
    }

    // Place the pointer back to the starting and loop through the vertices again
    ptr = vertex;
    while (ptr != NULL)
    {
        // If vertex not processed
        if (ptr->processed == 0)
        {
            // Insert the vertex into queue for processing
            insert_queue(ptr);
            ptr->processed = 1;

            // Loop for Deleting from queue and processing the vertex
            while (bottom != NULL)
            {
                // Deleting from queue and processing the vertex
                struct graphVertex *print = remove_queue();
                printf("%d, ", print->data);

                // Loop through the edges of the vertex
                struct graphArc *aptr = print->firstArc;
                while (aptr != NULL)
                {
                    // If vertex not processed
                    if (aptr->destination->processed == 0)
                    {
                        // Insert the vertex into queue for processing
                        insert_queue(aptr->destination);
                        aptr->destination->processed = 1;
                    }
                    aptr = aptr->nextArc;
                }
            }
        }
        ptr = ptr->nextVertex;
    }
}
