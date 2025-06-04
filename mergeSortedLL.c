#include <stdio.h>
#include <stdlib.h>

// Define the ListNode structure
struct ListNode {
    int data;
    struct ListNode *next;
};

// Merge two sorted linked lists
struct ListNode* mergeTwoList(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    current->next = l1 ? l1 : l2;
    return dummy.next;
}

// Create a new node
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append node to a linked list
void appendNode(struct ListNode** head, int data) {
    struct ListNode* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct ListNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Print the linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;
    int n1, n2, val;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter %d sorted elements for List 1:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        appendNode(&list1, val);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter %d sorted elements for List 2:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        appendNode(&list2, val);
    }

    printf("\nList 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct ListNode* mergedList = mergeTwoList(list1, list2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
