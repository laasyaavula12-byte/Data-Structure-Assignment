#include <stdio.h>

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

// enqueue
void enqueue(int x) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Full\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        cq[rear] = x;
    }
}

// dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue Empty\n");
    } else {
        printf("Removed: %d\n", cq[front]);

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

// display
void display() {
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
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