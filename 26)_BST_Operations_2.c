#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

void init_BST(BSTNode** root);
BSTNode* create_node(int x);
void add_node(BSTNode** root, int x);
void inorder(BSTNode* root);
void preorder(BSTNode* root);
void postorder(BSTNode* root);
int delete_BST(BSTNode** root, int x);

int main() {
    BSTNode* root = NULL;
    int x, choice, deleted_element;
    init_BST(&root);

    while (1) {
        scanf("%d", &choice);

        if (choice == 0) {
            init_BST(&root);
        } else if (choice == 1) {
            scanf("%d", &x);
            add_node(&root, x);
        } else if (choice == 2) {
            inorder(root);
            printf("\n");
        } else if (choice == 3) {
            preorder(root);
            printf("\n");
        } else if (choice == 4) {
            postorder(root);
            printf("\n");
        } else if (choice == 5) {
            // Search element
        } else if (choice == 6) {
            scanf("%d", &x);
            deleted_element = delete_BST(&root, x);
            printf("%d\n", deleted_element);
        } else {
            break;
        }
    }
    return 0;
}

void init_BST(BSTNode** root) {
    *root = NULL;
}

BSTNode* create_node(int x) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void add_node(BSTNode** root, int x) {
    if (*root == NULL) {
        *root = create_node(x);
    } else {
        if (x < (*root)->data) {
            add_node(&((*root)->left), x);
        } 
        else if (x > (*root)->data) {
            add_node(&((*root)->right), x);
        }
        else
            printf("DUPLICATE ELEMENT %d NOT INSERTED\n",x);
    }
}

void inorder(BSTNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}

void preorder(BSTNode* root) {
    if (root != NULL) {
        printf("%d, ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BSTNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d, ", root->data);
    }
}

int delete_BST(BSTNode** root, int x) {
    if (*root == NULL) {
        return -9999; // Element not found
    }

    if (x < (*root)->data) {
        return delete_BST(&((*root)->left), x);
    } else if (x > (*root)->data) {
        return delete_BST(&((*root)->right), x);
    } else {
        BSTNode* temp;
        int deleted_element = (*root)->data;

        if ((*root)->left == NULL) {
            temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            BSTNode* succ_parent = *root;
            BSTNode* succ = (*root)->right;

            while (succ->left != NULL) {
                succ_parent = succ;
                succ = succ->left;
            }

            if (succ_parent != *root) {
                succ_parent->left = succ->right;
            } else {
                succ_parent->right = succ->right;
            }

            (*root)->data = succ->data;
            free(succ);
        }

        return deleted_element;
    }
}
