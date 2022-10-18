#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct graphVertex * data;
    struct Node *next;
};
struct Node *bottom = NULL;
struct Node *top = NULL;

void insert(struct graphVertex * element)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;
    if (bottom == NULL)
        bottom = top = newNode;
    else
    {
        top->next = newNode;
        top = newNode;
    }
}

struct graphVertex * delete ()
{
    if (bottom == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        struct Node *temp = bottom;
        int element = bottom->data; // to store data of top node
        bottom = bottom->next;
        if (bottom == NULL)
            top == bottom;
        free(temp); // deleting the node
        return element;
    }
}

struct Data{
    int data;
};

struct graphArc{

    struct graphVertex *destination;
    struct graphArc *nextArc;
};

struct graphVertex{

    struct graphVertex *nextVertex;
    struct Data* data;
    int processed;
    struct graphArc *firstArc;
};

struct graphVertex* addGraphArc(struct graphVertex* vertex,struct Data* a,struct Data* b){

    struct graphVertex *ptr = vertex;
    struct graphVertex *a_vertex = NULL, *b_vertex = NULL;
    while (ptr != NULL)
    {
        if (ptr->data == a)
            a_vertex = ptr;
        if (ptr->data == b)
            b_vertex = ptr;
        if(a_vertex!=NULL||b_vertex!=NULL)
            break;
        ptr = ptr->nextVertex;
    }

    if (a_vertex == NULL)
    {
        struct graphVertex *a_temp = (struct graphVertex *)malloc(sizeof(struct graphVertex));
        a_temp->nextVertex = NULL;
        a_temp->data = a;
        a_temp->processed = 0;
        a_temp->firstArc = NULL;

        a_vertex = a_temp;
        
        if (ptr == NULL){
            ptr = a_temp;
        }
        else{
            ptr->nextVertex = a_temp;
            ptr = ptr->nextVertex;
        }
    }

    if (b_vertex == NULL){
        struct graphVertex *b_temp = (struct graphVertex *)malloc(sizeof(struct graphVertex));
        b_temp->nextVertex = NULL;
        b_temp->data = b;
        b_temp->processed = 0;
        b_temp->firstArc = NULL;
        
        b_vertex = b_temp;
        
        ptr->nextVertex = b_temp;
        ptr = ptr->nextVertex;
    
    }


    struct graphArc *a_arc = NULL, *b_arc = NULL;
    struct graphArc *aptr = a_vertex->firstArc, *bptr = a_vertex->firstArc;

    while (aptr != NULL)
    {
        if (aptr->destination == b_vertex){
            b_arc = aptr;
            break;
        }
        aptr = aptr->nextArc;
    }

    while (bptr != NULL)
    {
        if (bptr->destination == a_vertex){
            a_arc = bptr;
            break;
        }
        bptr = bptr->nextArc;
    }

    if (a_arc == NULL)
    {
        struct graphArc *a_arc_temp = (struct graphVertex *)malloc(sizeof(struct graphVertex));
        a_arc_temp->nextArc = NULL;
        a_arc_temp->destination = a_vertex;

        a_arc = a_arc_temp;
        
        if (bptr == NULL){
            bptr = a_arc_temp;
        }
        else{
            bptr->nextArc = a_arc_temp;
            bptr = bptr->nextArc;
        }
    }

    if (b_arc == NULL)
    {
        struct graphArc *b_arc_temp = (struct graphVertex *)malloc(sizeof(struct graphVertex));
        b_arc_temp->nextArc = NULL;
        b_arc_temp->destination = b_vertex;

        b_arc = b_arc_temp;
        
        if (aptr == NULL){
            aptr = b_arc_temp;
        }
        else{
            aptr->nextArc = b_arc_temp;
            aptr = aptr->nextArc;
        }
    }

    if (vertex == NULL)
        return a_vertex;
    else
        return vertex;
}


void depth_first_recursion(struct graphVertex* vertex){


    if(vertex->processed == 1){
        return;
    }

    printf("%d", vertex->data->data);
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
    while (ptr != NULL)
    {
        if (ptr->processed == 0){
            struct Node* ptr2 = top;
            int in_queue = 0;
            while (ptr2 != NULL){
                if(ptr2->data == ptr)
                    in_queue = 1;
                ptr2 = ptr2->next;
            }
            if(in_queue == 0)
                insert(ptr);
            
            while(bottom!=NULL){
                ptr = delete ();
                ptr->processed = 1;

                struct graphArc *aptr = ptr->firstArc;
                while (aptr != NULL)
                {   
                    ptr2 = top;
                    in_queue = 0;
                    while (ptr2 != NULL){
                        if(ptr2->data == aptr->destination)
                            in_queue = 1;
                        ptr2 = ptr2->next;
                    }

                    if (in_queue==0 && aptr->destination->processed == 0){
                        insert(aptr->destination);
                    }
                    aptr = aptr->nextArc;
                }
            }
        }
        ptr = ptr->nextVertex;
    }
}

// 0 - 1
// | / | \
// 4 - 3 - 2