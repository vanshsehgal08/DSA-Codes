#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove all elements from the linked list that match a given value
void removeElements(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* curr = *head;
    struct Node* prev = NULL;

    while (curr != NULL) {
        if (curr->data == value) {
            if (prev == NULL) {
                *head = curr->next;
                free(curr);
                curr = *head;
            } else {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    printf("Elements matching %d removed from the linked list.\n", value);
}

// Function to partition the linked list based on a given value
struct Node* partitionLinkedList(struct Node* head, int x) {
    struct Node* beforeHead = NULL; // Head of the list containing nodes less than x
    struct Node* beforeTail = NULL; // Tail of the list containing nodes less than x
    struct Node* afterHead = NULL;  // Head of the list containing nodes greater than or equal to x
    struct Node* afterTail = NULL;  // Tail of the list containing nodes greater than or equal to x

    struct Node* curr = head;
    while (curr != NULL) {
        if (curr->data < x) {
            // Node less than x
            if (beforeHead == NULL) {
                beforeHead = curr;
                beforeTail = curr;
            } else {
                beforeTail->next = curr;
                beforeTail = curr;
            }
        } else {
            // Node greater than or equal to x
            if (afterHead == NULL) {
                afterHead = curr;
                afterTail = curr;
            } else {
                afterTail->next = curr;
                afterTail = curr;
            }
        }
        curr = curr->next;
    }

    if (beforeTail != NULL) {
        beforeTail->next = afterHead; // Combine the two lists
        return beforeHead;
    } else {
        return afterHead;
    }
}

// Function to delete the node with the smallest value
void deleteSmallestNode(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* smallestNode = *head;
    struct Node* prev = NULL;
    struct Node* curr = *head;

    while (curr != NULL) {
        if (curr->data < smallestNode->data) {
            smallestNode = curr;
            prev = prev;
        }
        prev = curr;
        curr = curr->next;
    }

    if (smallestNode == *head) {
        *head = (*head)->next;
    } else {
        prev->next = smallestNode->next;
    }

    free(smallestNode);
    printf("Node with the smallest value deleted from the linked list.\n");
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, n, value, x;

    printf("Enter the size of the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    do {
        printf("\n----- Menu -----\n");
        printf("1. Remove elements matching a given value\n");
        printf("2. Partition the linked list based on a given value\n");
        printf("3. Delete the node with the smallest value\n");
        printf("4. Display the linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to remove from the linked list: ");
                scanf("%d", &value);
                removeElements(&head, value);
                break;
            case 2:
                printf("Enter the value to partition the linked list: ");
                scanf("%d", &x);
                head = partitionLinkedList(head, x);
                printf("Linked list partitioned.\n");
                break;
            case 3:
                deleteSmallestNode(&head);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
