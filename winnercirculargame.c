#include <stdio.h>

int findTheWinner(int n, int k) {
    int queue[1000];
    int front = 0, rear = -1;
    for(int i = 0; i < n; i++) {
        queue[i] = i + 1;
    }
    int size = n;
    rear = n - 1;

    while(size > 1) {
        for(int i = 0; i < k - 1; i++) {
            int temp = queue[front];
            front = (front + 1) % 1000;
            rear = (rear + 1) % 1000;
            queue[rear] = temp;
        }

        // Eliminate the k-th person
        front = (front + 1) % 1000;
        size--;
    }

    return queue[front];
}

int main() {
    int n, k;
    printf("Enter number of players (n): ");
    scanf("%d", &n);
    printf("Enter k (every k-th person is eliminated): ");
    scanf("%d", &k);

    int winner = findTheWinner(n, k);
    printf("The winner is: %d\n", winner);

    return 0;
}
