#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for key-value pairs
typedef struct KeyValuePair {
    char* key;
    int value;
} 
KeyValuePair;

// Define a struct for the hash table
typedef struct HashTable {
    int size;
    KeyValuePair** table;
} 
HashTable;

// Define a hash function that computes an index for a key
int hash(char* key, int size) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += (int) key[i];
    }
    return sum % size;
}

// Define a function to create a new hash table
HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (KeyValuePair**) malloc(sizeof(KeyValuePair*) * size);
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Define a function to insert a key-value pair into the hash table
void insert(HashTable* hashTable, char* key, int value) {
    // Compute the index for the key
    int index = hash(key, hashTable->size);

    // Create a new key-value pair
    KeyValuePair* pair = (KeyValuePair*) malloc(sizeof(KeyValuePair));
    pair->key = key;
    pair->value = value;

    // Insert the pair into the table at the computed index
    hashTable->table[index] = pair;
}

// Define a function to get the value associated with a key in the hash table
int get(HashTable* hashTable, char* key) {
    // Compute the index for the key
    int index = hash(key, hashTable->size);

    // Look up the key-value pair at the computed index
    KeyValuePair* pair = hashTable->table[index];

    // If the key-value pair exists, return its value; otherwise, return -1
    if (pair != NULL && strcmp(pair->key, key) == 0) {
        return pair->value;
    } else {
        return -1;
    }
}

// Define a function to print the contents of the hash table
void printHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        KeyValuePair* pair = hashTable->table[i];
        if (pair != NULL) {
            printf("%s: %d\n", pair->key, pair->value);
        }
    }
}

// Define a main function to test the hash table implementation
int main() {
    // Create a new hash table with a size of 10
    HashTable* hashTable = createHashTable(10);

    // Insert some key-value pairs into the hash table
    insert(hashTable, "foo", 42);
    insert(hashTable, "bar", 13);
    insert(hashTable, "baz", 7);

    // Print the contents of the hash table
    printHashTable(hashTable);

    // Get the value associated with a key in the hash table
    int value = get(hashTable, "foo");
    printf("Value of 'foo': %d\n", value);

    // Free the memory used by the hash table and its contents
    for (int i = 0; i < hashTable->size; i++) {
        KeyValuePair* pair = hashTable->table[i];
        if (pair != NULL) {
            free(pair->key);
            free(pair);
        }
    }
    free(hashTable->table);
    free(hashTable);

    return 0;
}





