#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int data; 
    struct Node* next; 
}; 
struct Node* head = NULL; 
void insertStart(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->next = head; 
    head = newNode; 
} 
void insertEnd(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* temp = head; 
    newNode->data = data; 
    newNode->next = NULL; 
 
    if (head == NULL) { 
        head = newNode; 
    } else { 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        temp->next = newNode; 
    } 
} 
 
void insertAfter(int data, int target) { 
    struct Node* temp = head; 
    while (temp != NULL && temp->data != target) { 
        temp = temp->next; 
    } 
    if (temp == NULL) { 
        printf("Target %d not found.\n", target); 
    } else { 
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
        newNode->data = data; 
        newNode->next = temp->next; 
        temp->next = newNode; 
    } 
} 
 
void deleteData(int data) { 
    if (head == NULL) { 
        printf("List is empty!\n"); 
        return; 
    } 
 
    struct Node* temp = head; 
 
    if (temp != NULL && temp->data == data) { 
        head = temp->next; 
        free(temp); 
        return; 
    } 
 
    struct Node* prev = NULL; 
    while (temp != NULL && temp->data != data) { 
        prev = temp; 
        temp = temp->next; 
    } 
 
    if (temp == NULL) { 
        printf("Node with data %d not found.\n", data); 
        return; 
    } 
    prev->next = temp->next; 
    free(temp); 
} 
 
void deleteLastData(int data) { 
    if (head == NULL) { 
        printf("List is empty!\n"); 
        return; 
    } 
 
    struct Node* temp = head; 
    struct Node* prev = NULL; 
 
    if (temp != NULL && temp->data == data) { 
        head = temp->next; 
        free(temp); 
        return; 
    } 
 
    while (temp != NULL && temp->data != data) { 
        prev = temp; 
        temp = temp->next; 
    } 
 
    if (temp == NULL) { 
        printf("Node with data %d not found.\n", data); 
        return; 
    } 
 
    prev->next = temp->next; 
    free(temp); 
} 
 
void printList() { 
    struct Node* temp = head; 
    if (temp == NULL) { 
        printf("List is empty!\n"); 
        return; 
    } 
    while (temp != NULL) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
int main() { 
    int choice, data, target; 
    while (1) { 
        printf("\n1. Insert at Start\n2. Insert at End\n3. Insert After Data\n4. Delete Data\n5. Delete Last Data\n6. Print List\n7. Exit\n"); 
        printf("Enter your choice: ");          
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data to insert at start: "); 
                scanf("%d", &data); 
                insertStart(data); 
                break; 
            case 2: 
                printf("Enter data to insert at end: "); 
                scanf("%d", &data); 
                insertEnd(data); 
                break; 
            case 3: 
                printf("Enter data to insert and target data: "); 
                scanf("%d %d", &data, &target); 
                insertAfter(data, target); 
                break; 
            case 4: 
                printf("Enter data to delete from list: "); 
                scanf("%d", &data); 
                deleteData(data); 
                break; 
            case 5: 
                printf("Enter data to delete last occurrence from list: "); 
                scanf("%d", &data); 
                deleteLastData(data); 
                break; 
            case 6: 
                printList(); 
                break; 
            case 7: 
                printf("Exiting program.\n"); 
                exit(0); 
            default: 
                printf("Invalid choice!\n"); 
        } 
 
        printf("\nDo you want to continue (1 for Yes, 0 for No): "); 
        int cont; 
        scanf("%d", &cont); 
 
        if (cont == 0) { 
            printf("Final list:\n"); 
            printList(); 
            break; 
        } 
    }
    return 0;

} 
