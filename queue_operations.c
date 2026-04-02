#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// enqueue
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Full\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = x;
    }
}

// dequeue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
    } else {
        printf("Deleted: %d\n", queue[front++]);
    }
}

// display
void display() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}