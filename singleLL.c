#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to insert a node at end
void insert(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node by value
void deleteByValue(int val) {
    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found.\n", val);
        return;
    }

    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Value %d deleted.\n", val);
}

// Function to search for a value
void search(int val) {
    struct Node *temp = head;
    int pos = 0;

    while (temp != NULL) {
        if (temp->data == val) {
            printf("Value %d found at position %d\n", val, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value %d not found.\n", val);
}

// Function to reverse the list
void reverse() {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed.\n");
}

// Function to sort the list
void sort() {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted.\n");
}

// Function to display the list
void display() {
    struct Node *temp = head;
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main menu
int main() {
    int choice, val;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Reverse\n5. Sort\n6. Display\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteByValue(val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 4:
                reverse();
                break;
            case 5:
                sort();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
