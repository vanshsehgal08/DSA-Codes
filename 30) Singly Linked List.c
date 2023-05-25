#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Node inserted at the beginning.\n");
}

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

    printf("Node inserted at the end.\n");
}

// Function to insert a node at a given position in the linked list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", position);
}

// Function to delete a node at the beginning of the linked list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;
    free(temp);

    printf("Node deleted from the beginning.\n");
}

// Function to delete a node at the end of the linked list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }

    struct Node* prev = NULL;
    struct Node* curr = *head;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    free(curr);

    printf("Node deleted from the end.\n");
}

// Function to delete a node at a given position in the linked list
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

    struct Node* prev = NULL;
    struct Node* curr = *head;
    for (int i = 1; i < position; i++) {
        if (curr == NULL) {
            printf("Invalid position.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = curr->next;
    free(curr);

    printf("Node deleted from position %d.\n", position);
}

// Function to delete a node with a particular value from the linked list
void deleteWithValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* prev = NULL;
    struct Node* curr = *head;
    while (curr != NULL) {
        if (curr->data == value) {
            if (prev == NULL) {
                *head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("Node with value %d deleted.\n", value);
            
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Node with value %d not found.\n", value);
}

// Function to search for a value in the linked list
void search(struct Node* head, int value) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Value %d not found in the linked list.\n", value);
}

// Function to find the nth node from the end of the linked list
void printNthNodeFromEnd(struct Node* head, int n) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* fast = head;
    struct Node* slow = head;

    // Move fast pointer 'n' nodes ahead
    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            printf("Invalid position.\n");
            return;
        }
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    printf("Value at position %d from the end: %d\n", n, slow->data);
}

// Function to delete the nth node from the end of the linked list
void deleteNthNodeFromEnd(struct Node** head, int n) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* fast = *head;
    struct Node* slow = *head;
    struct Node* prev = NULL;

    // Move fast pointer 'n' nodes ahead
    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            printf("Invalid position.\n");
            return;
        }
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }

    // If the nth node is the head node
    if (prev == NULL) {
        *head = (*head)->next;
    } else {
        prev->next = slow->next;
    }

    free(slow);

    printf("Node at position %d from the end deleted.\n", n);
}

// Function to find the length of the linked list
int findLength(struct Node* head) {
    int length = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
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
    int choice, data, position, value, n;

    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Delete particular element\n");
        printf("8. Search\n");
        printf("9. Print nth node from end\n");
        printf("10. Delete nth node from end\n");
        printf("11. Find length of linked list\n");
        printf("12. Display\n");
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
                printf("Enter the position from the end: ");
                scanf("%d", &n);
                printNthNodeFromEnd(head, n);
                break;
            case 10:
                printf("Enter the position from the end: ");
                scanf("%d", &n);
                deleteNthNodeFromEnd(&head, n);
                break;
            case 11:
                printf("Length of the linked list: %d\n", findLength(head));
                break;
            case 12:
                display(head);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
