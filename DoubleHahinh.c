#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define PRIME 7  // Use a prime smaller than MAX for h2()

int hashTable[MAX];

int h1(int key) {
    return key % MAX;
}

int h2(int key) {
    return PRIME - (key % PRIME);
}

void insert(int key) {
    int index1 = h1(key);
    int index2 = h2(key);
    int i = 0;
    int index;

    while (i < MAX) {
        index = (index1 + i * index2) % MAX;
        if (hashTable[index] == -1) {
            hashTable[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
        i++;
    }
    printf("Hash table is full, cannot insert %d\n", key);
}

void search(int key) {
    int index1 = h1(key);
    int index2 = h2(key);
    int i = 0;
    int index;

    while (i < MAX) {
        index = (index1 + i * index2) % MAX;
        if (hashTable[index] == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        } else if (hashTable[index] == -1) {
            break;
        }
        i++;
    }
    printf("Key %d not found in hash table\n", key);
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < MAX; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

int main() {
    int n, key, choice;

    // Initialize hash table
    for (int i = 0; i < MAX; i++)
        hashTable[i] = -1;

    while (1) {
        printf("\n*** Double Hashing Menu ***\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            search(key);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}