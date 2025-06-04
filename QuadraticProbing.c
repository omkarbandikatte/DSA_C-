#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main() {
    int hashTable[MAX];
    for (int i = 0; i < MAX; i++) {
        hashTable[i] = -1; // Initialize hash table with -1
    }

    int n, key, hkey, index, i;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    
    for (int j = 0; j < n; j++) {
        printf("Enter key %d: ", j + 1);
        scanf("%d", &key);

        hkey = key % MAX; // Hash function
        i = 0;
        index = (hkey + i * i) % MAX;

        while (hashTable[index] != -1 && i < MAX) {
            i++;
            index = (hkey + i * i) % MAX;
        }

        if (i < MAX) {
            hashTable[index] = key; // Insert key into hash table
        } else {
            printf("Hash table is full, cannot insert %d\n", key);
        }
    }

    // Search operation
    printf("Enter value to search: ");
    scanf("%d", &key);

    hkey = key % MAX;
    i = 0;
    index = (hkey + i * i) % MAX;

    while (i < MAX && hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("Key %d found at index %d\n", key, index);
            break;
        }
        i++;
        index = (hkey + i * i) % MAX;
    }

    if (i == MAX || hashTable[index] == -1) {
        printf("Key %d not found in hash table\n", key);
    }

    // Display hash table
    printf("Hash Table:\n");
    for (int i = 0; i < MAX; i++) {
        printf("Index %d: %d\n", i, hashTable[i]);
    }

    return 0;
}
