#include <stdio.h> // Header Files
#include <stdlib.h>

// MACROS for hashing
#define modulo_hash(key, list_size) (key % list_size)
#define offset_hash(key, list_size) (key / list_size)

// List Element struct whose array will create our list
struct ListElement
{
    unsigned int key;
    int is_filled;
    int data;
};

// Prototyping the functions
unsigned int insert(char const *, int, int, struct ListElement *, int);
int search(unsigned int key, struct ListElement *, int);
struct ListElement *createEmptyList(int size);

// Driver Code
int main()
{
    // Creating a list of size 307 (prime number)
    int size = 307;
    struct ListElement *list = createEmptyList(size);

    // Inserting the values 10 at key "Saksham",
    // 12 at "Gupta" and 14 at "DS file"
    unsigned int key1 = insert("Saksham", 7, 10, list, size);
    unsigned int key2 = insert("Gupta", 5, 12, list, size);
    unsigned int key3 = insert("DS file", 7, 14, list, size);

    // Searching and printing the values at the keys
    printf("Searching in the hashed list key \"Saksham\":\n%d\n", search(key1, list, size));
    printf("Searching in the hashed list key \"Gupta\":\n%d\n", search(key2, list, size));
    printf("Searching in the hashed list key \"DS file\":\n%d\n", search(key3, list, size));

    return 0;
}

unsigned int string_to_key(char const *key_string, int size)
{
    // This function converts the string to a number key using various hashing methods

    unsigned int key = 0;
    unsigned int key_copy;
    for (int i = 0; i < size; i++)
    {
        key_copy = key; // ROTATION HASHING
        key >>= 12;
        key_copy <<= sizeof(int) * 8 - 12;
        key += key_copy;

        key += key_string[i]; // FOLD HASHING
    }

    return key;
}

void insert_recursion(unsigned int key, int hashed_key, int data, struct ListElement *list, int size)
{
    // This function inserts the given value at given hash key

    // If the hashed key address is not filled or is filled by the same integer key
    if (list[hashed_key].is_filled == 0 || list[hashed_key].key == key)
    {

        // Fill the adress
        list[hashed_key].is_filled = 1;
        list[hashed_key].key = key;
        list[hashed_key].data = data;
        return;
    }
    else
    {
        // COLLISION

        // Resolution by douuble hashing method
        hashed_key = hashed_key + offset_hash(key, size);
        insert_recursion(key, hashed_key, data, list, size);
    }
}

unsigned int insert(char const *key, int string_size, int data, struct ListElement *list, int size)
{
    // This function inserts the given value at given string key

    // Converts the string key to integer key
    unsigned int key_int = string_to_key(key, string_size);

    // Uses a recursion function to store the value at the given integer key
    // Uses the hash key as modulo hash
    insert_recursion(key_int, modulo_hash(key_int, size), data, list, size);
    return key_int;
}

int search_recursion(unsigned int key, int hashed_key, struct ListElement *list, int size)
{
    // This function searches the value at given hash key

    // If the hashed key address is not filled or is filled by the same integer key
    if (list[hashed_key].is_filled == 1 && list[hashed_key].key == key)

        // return data
        return list[hashed_key].data;
    else
    {
        // COLLISION

        // Resolution by douuble hashing method
        hashed_key = hashed_key + offset_hash(key, size);
        return search_recursion(key, hashed_key, list, size);
    }
}

int search(unsigned int key, struct ListElement *list, int size)
{
    // This function searches the value at the given integer key

    // Uses a recursion function to search the value at the given integer key
    // Uses the hash key as modulo hash since stored the same
    return search_recursion(key, modulo_hash(key, size), list, size);
}

struct ListElement *createEmptyList(int size)
{

    // Allocate the memory for the list of given size
    struct ListElement *list = (struct ListElement *)malloc(size * (sizeof(struct ListElement)));

    // Set All elements as not filled
    for (int i = 0; i < size; i++)
        list[i].is_filled = 0;

    return list;
}
