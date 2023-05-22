#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeg(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Function to remove duplicates from the linked list
void removeDuplicates(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL && current->next != NULL) {
        nextNode = current;
        while (nextNode->next != NULL) {
            if (current->data == nextNode->next->data) {
                struct Node* duplicateNode = nextNode->next;
                nextNode->next = nextNode->next->next;
                free(duplicateNode);
            } else {
                nextNode = nextNode->next;
            }
        }
        current = current->next;
    }

    printf("Duplicates removed successfully.\n");
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked list elements: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    // Menu-driven program to insert elements into the linked list
    do {
        printf("\n**** Linked List Menu ****\n");
        printf("1. Insert at the beginning\n");
        printf("2. Remove duplicates\n");
        printf("3. Display the linked list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertAtBeg(&head, data);
                break;
            case 2:
                removeDuplicates(head);
                break;
            case 3:
                displayList(head);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
