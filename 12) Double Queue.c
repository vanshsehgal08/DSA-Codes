#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Deque {
    int data[MAX_SIZE];
    int front, rear;
};

void initializeDeque(struct Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(struct Deque *dq) {
    if ((dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1)) {
        // Deque is full if the front and rear are adjacent or at the ends of the array
        return 1;
    }
    return 0;
}

int isEmpty(struct Deque *dq) {
    if (dq->front == -1) {
        // Deque is empty if the front is -1
        return 1;
    }
    return 0;
}

void enqueueF(struct Deque *dq, int item) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot enqueue.\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX_SIZE - 1;
    } else {
        dq->front--;
    }

    dq->data[dq->front] = item;
    printf("Enqueued element %d at the front.\n", item);
}

void enqueueR(struct Deque *dq, int item) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot enqueue.\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == MAX_SIZE - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->data[dq->rear] = item;
    printf("Enqueued element %d at the rear.\n", item);
}

void dequeueF(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot dequeue.\n");
        return;
    }

    printf("Dequeued element %d from the front.\n", dq->data[dq->front]);

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == MAX_SIZE - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

void dequeueR(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot dequeue.\n");
        return;
    }

    printf("Dequeued element %d from the rear.\n", dq->data[dq->rear]);

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX_SIZE - 1;
    } else {
        dq->rear--;
    }
}

void display(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d ", dq->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", dq->data[dq->rear]);
}

int main() {
    struct Deque dq;
    initializeDeque(&dq);

    int choice, item;

    while (1) {
        printf("\n---- Double-Ended Queue Operations ----\n");
        printf("1. Enqueue at the Front\n");
        printf("2. Enqueue at the Rear\n");
        printf("3. Dequeue from the Front\n");
        printf("4. Dequeue from the Rear\n");
        printf("5. Display the Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue at the front: ");
                scanf("%d", &item);
                enqueueF(&dq, item);
                break;
            case 2:
                printf("Enter the element to enqueue at the rear: ");
                scanf("%d", &item);
                enqueueR(&dq, item);
                break;
            case 3:
                dequeueF(&dq);
                break;
            case 4:
                dequeueR(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
