#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node to be deleted found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        struct Node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to search for a node in BST
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return searchNode(root->left, data);
    else
        return searchNode(root->right, data);
}

// Function to find the maximum node in BST
struct Node* findMaxNode(struct Node* root) {
    if (root == NULL || root->right == NULL)
        return root;

    return findMaxNode(root->right);
}

// Function to find the minimum node in BST
struct Node* findMinNode(struct Node* root) {
    if (root == NULL || root->left == NULL)
        return root;

    return findMinNode(root->left);
}

// Function to find the kth maximum node in BST
void findKthMaxNode(struct Node* root, int k, int* count) {
    if (root == NULL || *count >= k)
        return;

    findKthMaxNode(root->right, k, count);

    (*count)++;
    if (*count == k) {
        printf("Kth maximum node: %d\n", root->data);
        return;
    }

    findKthMaxNode(root->left, k, count);
}

// Function to find the kth minimum node in BST
void findKthMinNode(struct Node* root, int k, int* count) {
    if (root == NULL || *count >= k)
        return;

    findKthMinNode(root->left, k, count);

    (*count)++;
    if (*count == k) {
        printf("Kth minimum node: %d\n", root->data);
        return;
    }

    findKthMinNode(root->right, k, count);
}

// Function for inorder traversal of BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function for postorder traversal of BST
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function for preorder traversal of BST
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data, k, count = 0;

    do {
        printf("\n----- Binary Search Tree Menu -----");
        printf("\n1. Add a node");
        printf("\n2. Delete a node");
        printf("\n3. Search a node");
        printf("\n4. Print Maximum node");
        printf("\n5. Print Minimum node");
        printf("\n6. Print kth Maximum node");
        printf("\n7. Print kth Minimum node");
        printf("\n8. Inorder traversal");
        printf("\n9. Postorder traversal");
        printf("\n10. Preorder traversal");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting the program...\n");
                break;
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                printf("Node inserted successfully!\n");
                break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Node deleted successfully!\n");
                break;
            case 3:
                printf("Enter the data to be searched: ");
                scanf("%d", &data);
                if (searchNode(root, data) != NULL)
                    printf("Node found in the BST!\n");
                else
                    printf("Node not found in the BST!\n");
                break;
            case 4:
                if (root == NULL)
                    printf("BST is empty!\n");
                else
                    printf("Maximum node: %d\n", findMaxNode(root)->data);
                break;
            case 5:
                if (root == NULL)
                    printf("BST is empty!\n");
                else
                    printf("Minimum node: %d\n", findMinNode(root)->data);
                break;
            case 6:
                printf("Enter the value of k: ");
                scanf("%d", &k);
                count = 0;
                if (k <= 0)
                    printf("Invalid value of k!\n");
                else if (root == NULL)
                    printf("BST is empty!\n");
                else
                    findKthMaxNode(root, k, &count);
                break;
            case 7:
                printf("Enter the value of k: ");
                scanf("%d", &k);
                count = 0;
                if (k <= 0)
                    printf("Invalid value of k!\n");
                else if (root == NULL)
                    printf("BST is empty!\n");
                else
                    findKthMinNode(root, k, &count);
                break;
            case 8:
                if (root == NULL)
                    printf("BST is empty!\n");
                else {
                    printf("Inorder traversal: ");
                    inorderTraversal(root);
                    printf("\n");
                }
                break;
            case 9:
                if (root == NULL)
                    printf("BST is empty!\n");
                else {
                    printf("Postorder traversal: ");
                    postorderTraversal(root);
                    printf("\n");
                }
                break;
            case 10:
                if (root == NULL)
                    printf("BST is empty!\n");
                else {
                    printf("Preorder traversal: ");
                    preorderTraversal(root);
                    printf("\n");
                }
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
