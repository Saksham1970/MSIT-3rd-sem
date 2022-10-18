#include<stdio.h>

#define modulo_hash(key, list_size) (key % list_size)
#define offset_hash(key, list_size) (key/list_size)

struct Data{
    int data;
};

struct ListElement
{
    int key;
    int is_filled;
    struct Data data;
};

unsigned int string_to_key(char *key_string, int size)
{

    unsigned int key = 0;
    unsigned int key_copy;
    for (int i = 0; i < size; i++)
    {
        key_copy = key;     // ROTATION HASHING
        key >>= 12;
        key_copy <<= sizeof(int) * 8 - 12;
        key += key_copy;

        key += key_string[i];   // FOLD HASHING
    }

    return key;
}

void insert(int key, int hashed_key, struct Data data, struct ListElement* list, int size){
    if (list[hashed_key].is_filled == 0 || list[hashed_key].key == key){

        list[hashed_key].is_filled = 1;
        list[hashed_key].key = key;
        list[hashed_key].data = data;
        return;
    }
    else{
        // COLLISION

        // Resolution by douuble hashing method
        hashed_key = hashed_key + offset_hash(key, size);
        insert(key, hashed_key, data, list, size);
    }
}

struct Data search(int key, int hashed_key, struct ListElement* list, int size){

    if (list[hashed_key].is_filled == 1 && list[hashed_key].key == key)
        return list[hashed_key].data;

    else{
        // COLLISION

        // Resolution by douuble hashing method
        hashed_key = hashed_key + offset_hash(key, size);
        search(key, hashed_key, list, size);
    }

}

struct ListElement* createEmptyList(int size){

    struct ListElement *list = (struct ListElement *)malloc(size * (sizeof(struct ListElement)));
    for (int i = 0; i < size; i++)
        list[i].is_filled = 0;
}
