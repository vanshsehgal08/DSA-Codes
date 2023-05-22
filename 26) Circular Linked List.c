#include <stdio.h>
#include <stdlib.h>

// Circular linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
    }
    *head = newNode;
    printf("Node inserted at the beginning.\n");
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
    printf("Node inserted at the end.\n");
}

// Function to insert a node at a given position in the circular linked list
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
        if (current == *head) {
            printf("Invalid position.\n");
            return;
        }
    }

    newNode->next = current->next;
    current->next = newNode;
    printf("Node inserted at position %d.\n", position);
}

// Function to delete a node at the beginning of the circular linked list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = *head;
    if (current->next == *head) {
        *head = NULL;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = current->next;
        last->next = *head;
    }

    free(current);
    printf("Node deleted from the beginning.\n");
}

// Function to delete a node at the end of the circular linked list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current->next != *head) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = *head;
    }

    free(current);
    printf("Node deleted from the end.\n");
}

// Function to delete a node at a given position in the circular linked list
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
    struct Node* prev = NULL;
    int count = 1;
    while (count < position) {
        prev = current;
        current = current->next;
        count++;
        if (current == *head) {
            printf("Invalid position.\n");
            return;
        }
    }

    prev->next = current->next;
    free(current);
    printf("Node deleted from position %d.\n", position);
}

// Function to delete a node with a particular value from the circular linked list
void deleteWithValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current->next != *head) {
        if (current->data == value) {
            break;
        }
        prev = current;
        current = current->next;
    }

    if (current->data != value) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if (current == *head) {
        *head = current->next;
    }

    prev->next = current->next;
    free(current);
    printf("Node with value %d deleted.\n", value);
}

// Function to search for a value in the circular linked list
void search(struct Node* head, int value) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    int position = 1;
    do {
        if (current->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        current = current->next;
        position++;
    } while (current != head);

    printf("Value %d not found in the linked list.\n", value);
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Circular linked list elements: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, value;

    do {
        printf("\nCircular Linked List Operations:\n");
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
