#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Linked list node structure
struct Node {
    void* data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(void* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, void* data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // Find the middle node of the linked list
    struct Node* slowPtr = head;
    struct Node* fastPtr = head;

    while (fastPtr->next != NULL && fastPtr->next->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // Reverse the second half of the linked list
    struct Node* secondHalf = reverseList(slowPtr->next);

    // Compare the first half with the reversed second half
    struct Node* p1 = head;
    struct Node* p2 = secondHalf;

    while (p2 != NULL) {
        if (memcmp(p1->data, p2->data, sizeof(char)) != 0) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // Restore the original linked list by reversing the second half again
    reverseList(secondHalf);

    return true;
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%c ", *((char*)current->data));
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Node* head = NULL;
    char data[100];
    int length, i;

    printf("Enter the length of the list: ");
    scanf("%d", &length);

    printf("Enter the elements of the list: ");
    for (i = 0; i < length; i++) {
        scanf(" %c", &data[i]);
        insertAtBeginning(&head, &data[i]);
    }

    printf("Original list: ");
    display(head);

    struct Node* reversedHead = reverseList(head);
    printf("Reversed list: ");
    display(reversedHead);

    if (isPalindrome(reversedHead)) {
        printf("The reversed list is a palindrome.\n");
    } else {
        printf("The reversed list is not a palindrome.\n");
    }

    freeList(reversedHead);

    return 0;
}
