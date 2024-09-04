#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Define the structure for a hash table
struct HashTable {
    int* table;
    int size;
};

// Function to create a hash table
struct HashTable* createHashTable(int size) {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    hashTable->size = size;
    hashTable->table = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        hashTable->table[i] = -1; // Initialize all elements to -1 (indicating empty slots)
    }

    return hashTable;
}

// Hash function
int hashFunction(int key, int size) {
    return key % size;
}

// Function to insert a key into the hash table using linear probing
void insert(struct HashTable* hashTable, int key) {
    int index = hashFunction(key, hashTable->size);
    
    // Linear probing in case of collision
    while (hashTable->table[index] != -1) {
        index = (index + 1) % hashTable->size;
    }

    hashTable->table[index] = key;
}

// Function to search for a key in the hash table
int search(struct HashTable* hashTable, int key) {
    int index = hashFunction(key, hashTable->size);
    int startIndex = index;

    while (hashTable->table[index] != -1) {
        if (hashTable->table[index] == key) {
            return index; // Key found
        }
        index = (index + 1) % hashTable->size;

        // If we return to the start index, the key is not present
        if (index == startIndex) {
            break;
        }
    }

    return -1; // Key not found
}

// Function to display the hash table
void display(struct HashTable* hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < hashTable->size; i++) {
        if (hashTable->table[i] != -1) {
            printf("Index %d: %d\n", i, hashTable->table[i]);
        } else {
            printf("Index %d: ~\n", i);
        }
    }
}

// Main function
int main() {
    struct HashTable* hashTable = createHashTable(SIZE);

    insert(hashTable, 23);
    insert(hashTable, 43);
    insert(hashTable, 13);
    insert(hashTable, 27);
    insert(hashTable, 33);

    printf("Hash table after inserting elements:\n");
    display(hashTable);

    int key = 27;
    int index = search(hashTable, key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the hash table.\n", key);
    }

    return 0;
}
