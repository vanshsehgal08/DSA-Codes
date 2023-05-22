#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
    printf("Node inserted at the beginning.\n");
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }
    printf("Node inserted at the end.\n");
}

// Function to insert a node at a given position in the doubly linked list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* current = *head;

    int count = 1;
    while (count < position - 1) {
        current = current->next;
        count++;
        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    printf("Node inserted at position %d.\n", position);
}

// Function to delete a node at the beginning of the doubly linked list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = *head;
    *head = current->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(current);
    printf("Node deleted from the beginning.\n");
}

// Function to delete a node at the end of the doubly linked list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(current);
    printf("Node deleted from the end.\n");
}

// Function to delete a node at a given position in the doubly linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* current = *head;

    int count = 1;
    while (count < position) {
        current = current->next;
        count++;
        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Node deleted from position %d.\n", position);
}

// Function to delete a node with a particular value from the doubly linked list
void deleteWithValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = *head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Node with value %d deleted.\n", value);
}

// Function to search for a value in the doubly linked list
void search(struct Node* head, int value) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    int position = 1;
    while (current != NULL && current->data != value) {
        current = current->next;
        position++;
    }

    if (current != NULL) {
        printf("Value %d found at position %d.\n", value, position);
    } else {
        printf("Value %d not found in the linked list.\n", value);
    }
}

// Function to display the doubly linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Doubly linked list elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, value;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Delete particular element\n");
        printf("8. Search\n");
        printf("9. Display\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                deleteWithValue(&head, value);
                break;
            case 8:
                printf("Enter the value to be searched: ");
                scanf("%d", &value);
                search(head, value);
                break;
            case 9:
                display(head);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

