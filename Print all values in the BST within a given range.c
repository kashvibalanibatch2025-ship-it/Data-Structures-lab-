#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void rangeQuery(struct Node* root, int low, int high) {
    if (root == NULL) return;

    if (root->data > low)
        rangeQuery(root->left, low, high);

    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    if (root->data < high)
        rangeQuery(root->right, low, high);
}

int main() {
    printf("Name: Kashvi Balani\n");
    printf("PRN: 25070521111\n");
    printf("Batch: B2\n\n");

    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->right = createNode(18);

    int low = 7, high = 15;

    printf("Nodes in range: ");
    rangeQuery(root, low, high);

    printf("\n");

    return 0;
}
