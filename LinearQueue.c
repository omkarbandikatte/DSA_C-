#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int QUEUE[MAX];
int front = -1, rear = -1;

int isFull() {
    return (rear == MAX - 1);
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    QUEUE[++rear] = value;
    printf("Inserted %d\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Underflow\n");
        return -1;
    }
    int value = QUEUE[front++];
    return value;
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", QUEUE[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued %d\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}