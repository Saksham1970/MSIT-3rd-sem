#include <stdio.h>
#include <stdlib.h>

// For Stack
struct Node
{
    struct graphVertex * vertex;
    struct Node *next;
};
struct Node *bottom = NULL;
struct Node *top = NULL;


struct graphArc{

    struct graphVertex *destination;
    struct graphArc *nextArc;
};

struct graphVertex{

    struct graphVertex *nextVertex;
    int data;
    int processed;
    struct graphArc *firstArc;
};

void depth_first_traversal(struct graphVertex *);
void breadth_first_traversal(struct graphVertex *);
struct graphVertex *dummyGraph();

int main(){
    char graph_representation[25] = "0 - 1\n| / | \\\n4 - 3 - 2";
    
    struct graphVertex *vertex = dummyGraph();
    
    printf("Graph:\n%s",graph_representation);
    // printf("\nDFS traversal:\n");
    // depth_first_traversal(vertex);

    printf("\nBFS traversal:\n");
    breadth_first_traversal(vertex);

    return 0;
}

void insert_queue(struct graphVertex * vertex)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }
    newNode->vertex = vertex;
    newNode->next = NULL;
    if (bottom == NULL)
        bottom = top = newNode;
    else
    {
        top->next = newNode;
        top = newNode;
    }
}

struct graphVertex * remove_queue ()
{
    if (bottom == NULL)
    {
        printf("Underflow\n");
        return NULL;
    }
    else
    {
        struct Node *temp = bottom;
        struct graphVertex * element = bottom->vertex; // to store data of top node
        bottom = bottom->next;
        if (bottom == NULL)
            top == bottom;
        free(temp); // deleting the node
        return element;
    }
}

struct graphVertex* addGraphEdge(struct graphVertex* vertex,int a, int b){

    struct graphVertex *ptr = vertex;
    struct graphVertex *a_vertex = NULL, *b_vertex = NULL;

    if (ptr != NULL)
    {
        while (1)
        {
            if (ptr->data == a)
                a_vertex = ptr;
            if (ptr->data == b)
                b_vertex = ptr;
            if(a_vertex!=NULL&&b_vertex!=NULL)
                break;

            if (ptr->nextVertex == NULL)
                break;
            
            ptr = ptr->nextVertex;
        }

    }
    
    
    if (a_vertex == NULL)
    {
        struct graphVertex *a_temp = (struct graphVertex *)malloc(sizeof(struct graphVertex));
       
        a_temp->nextVertex = NULL;
        a_temp->data = a;
        a_temp->processed = 64;
        a_temp->firstArc = NULL;

        a_vertex = a_temp;
        
        if (ptr == NULL){
            ptr = a_vertex;
        }
        else{
            ptr->nextVertex = a_vertex;
            ptr = ptr->nextVertex;
        }   
    }

    if (b_vertex == NULL){
        
        struct graphVertex *b_temp = (struct graphVertex *)malloc(sizeof(struct graphVertex));
        b_temp->nextVertex = NULL;
        b_temp->data = b;
        b_temp->processed = 32;
        b_temp->firstArc = NULL;


        b_vertex = b_temp;
        
        ptr->nextVertex = b_vertex;
        ptr = ptr->nextVertex;
    
    }


    struct graphArc *a_arc = NULL, *b_arc = NULL;
    struct graphArc *aptr = a_vertex->firstArc, *bptr = b_vertex->firstArc;

    while (aptr != NULL)
    {
        if (aptr->destination == b_vertex){
            b_arc = aptr;
            break;
        }
        if (aptr->nextArc == NULL)
            break;
        aptr = aptr->nextArc;
    }

    while (bptr != NULL)
    {
        if (bptr->destination == a_vertex){
            a_arc = bptr;
            break;
        }
        if(bptr->nextArc == NULL)
            break;
        bptr = bptr->nextArc;
    }

    if (a_arc == NULL)
    {
        struct graphArc *a_arc_temp = (struct graphArc *)malloc(sizeof(struct graphArc));
        a_arc_temp->nextArc = NULL;
        a_arc_temp->destination = a_vertex;

        a_arc = a_arc_temp;
        
        if (bptr == NULL)
            b_vertex->firstArc = a_arc_temp;
        else
            bptr->nextArc = a_arc_temp;
        
    }
    if (b_arc == NULL)
    {
        struct graphArc *b_arc_temp = (struct graphArc *)malloc(sizeof(struct graphArc));
        b_arc_temp->nextArc = NULL;
        b_arc_temp->destination = b_vertex;

        b_arc = b_arc_temp;
        
        if (aptr == NULL)
            a_vertex->firstArc = b_arc_temp;
        else
            aptr->nextArc = b_arc_temp;
    }
    if (vertex == NULL)
        return a_vertex;
    else
        return vertex;
}

struct graphVertex *dummyGraph(){
    

    struct graphVertex* vertex = addGraphEdge(NULL, 0, 1); 
    addGraphEdge(vertex, 0, 4);
    addGraphEdge(vertex, 1, 3);
    addGraphEdge(vertex, 1, 4);
    addGraphEdge(vertex, 4, 3);
    addGraphEdge(vertex, 3, 2);
    addGraphEdge(vertex, 1, 2);
   
    return vertex;
}

void depth_first_recursion(struct graphVertex* vertex){


    if(vertex->processed == 1){
        return;
    }
   
    printf("%d, ", vertex->data);
    vertex->processed = 1;
    struct graphArc *ptr = vertex->firstArc;
    while (ptr != NULL)
    {
        depth_first_recursion(ptr->destination);
        ptr = ptr->nextArc;
    }
}

void depth_first_traversal(struct graphVertex* vertex){
    if(vertex == NULL)
        return;
    
    struct graphVertex *ptr = vertex;
    while (ptr != NULL)
    {
        ptr->processed = 0;
        ptr = ptr->nextVertex;
    }

    depth_first_recursion(vertex);
}

void breadth_first_traversal(struct graphVertex* vertex){

    if(vertex == NULL)
        return;
    
    struct graphVertex *ptr = vertex;
    
    while (ptr != NULL)
    {
        ptr->processed = 0;
        ptr = ptr->nextVertex;
    }

    ptr = vertex;
    printf("hello1\n");
    while (ptr != NULL)
    {
        if (ptr->processed == 0){
            struct Node* ptr2 = top;
            int in_queue = 0;
            while (ptr2 != NULL){
                if(ptr2->vertex == ptr){
                    in_queue = 1;
                    break;
                }
                ptr2 = ptr2->next;
            }
            if(in_queue == 0){
                
                insert_queue(ptr);
                printf("inserted %d\n", ptr->data);
                printf("top = %d\n",top->vertex->data);
            }
            while(bottom!=NULL){
                printf("here\n");
                struct graphVertex* print = remove_queue();
                print->processed = 1;
                printf("%d, ", print->data);

                struct graphArc *aptr = print->firstArc;
                while (aptr != NULL)
                {   
                    ptr2 = top;
                    in_queue = 0;
                    printf("%d", top);
                    while (ptr2 != NULL){
                        if(ptr2->vertex == aptr->destination){
                            in_queue = 1;
                            break;
                        }
                        ptr2 = ptr2->next;
                    }
                    printf("ey");
                    if (in_queue==0 && aptr->destination->processed == 0){
                        insert_queue(aptr->destination);
                    }
                    aptr = aptr->nextArc;
                }
                printf("outta here\n");
            }
        }
        ptr = ptr->nextVertex;
    }
}

