#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree() {
    char ch;
    printf("Enter data for node (enter '.' for NULL): ");
    scanf(" %c", &ch); // notice the space before %c to skip whitespace

    if (ch == '.') {
        return NULL;
    }

    Node* root = createNode(ch);
    printf("Enter left child of %c:\n", ch);
    root->left = buildTree();
    printf("Enter right child of %c:\n", ch);
    root->right = buildTree();
    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

int main() {
    Node* root = buildTree();
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
