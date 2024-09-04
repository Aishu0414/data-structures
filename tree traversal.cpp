#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inorder traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Preorder traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    // Create the root node
    struct Node* root = createNode(1);

    // Create the rest of the tree
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
