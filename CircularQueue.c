#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1 + SIZE) % SIZE)) {
        printf("Queue is Full (Overflow)\n");
        return;
    }
    if (front == -1) { // First element insertion
        front = rear = 0;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0; // Wrap around
    } else {
        rear++;
    }
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty (Underflow)\n");
        return;
    }

    int data = queue[front];
    printf("Deleted %d\n", data);

    if (front == rear) { // Only one element
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0; // Wrap around
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n*** Circular Queue Menu ***\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}