#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Function to insert a new element into BST
struct node* insert(struct node** root, int data) {
    // If the tree is empty, return a new node
    if (*root == NULL) {
        *root = newNode(data);
        return *root;
    }

    // Otherwise, recur down the tree
    if (data < (*root)->data) {
        (*root)->left = insert(&((*root)->left), data);
    }
    else if (data > (*root)->data) {
        (*root)->right = insert(&((*root)->right), data);
    }
    else {
        printf("DUPLICATE CANNOT BE INSERTED\n");
    }
    return *root;
}

// Function to perform inorder traversal of BST
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to perform preorder traversal of BST
void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Function to perform postorder traversal of BST
void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function to display the menu and handle user input
int main() {
    struct node* root = NULL;
    int choice, data;
    do {
        printf("\nMENU:\n");
        printf("1. Insert an element to BST\n");
        printf("2. Print inorder traversal\n");
        printf("3. Print preorder traversal\n");
        printf("4. Print postorder traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);

    return 0;
}

