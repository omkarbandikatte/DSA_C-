#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int main() {
    int hashTable[MAX];
    for (int i = 0; i < MAX; i++) {
        hashTable[i] = -1; // Initialize hash table with -1
    }

    int n, key, hkey, index, i;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        i=0;
        hkey = key % MAX; // Hash function
        index = (hkey + i) % MAX; // Linear probing
        while (hashTable[index] != -1) {
            i++;
            index = (hkey + i) % MAX; // Linear probing
        }

        if(i<MAX) {
            hashTable[index] = key; // Insert key into hash table
        } else {
            printf("Hash table is full, cannot insert %d\n", key);
        }
    }    
    printf("Enter value to search:- ");
    scanf("%d", &key);
    i=0;
    hkey = key % MAX; // Hash function
    index = (hkey + i) % MAX; // Linear probing
    while(i<MAX && hashTable[index] != -1) {
        if(hashTable[index] == key) {
            printf("Key %d found at index %d\n", key, index);
            break;
        }
        i++;
        index = (hkey + i) % MAX; // Linear probing
    }

    if(i == MAX || hashTable[index] == -1){
        printf("Key %d not found in hash table\n", key);
    }

    printf("Hash Table:\n");
    for(int i = 0; i < MAX; i++) {
        printf("%d\n",hashTable[i]);
    }
    return 0;
}


