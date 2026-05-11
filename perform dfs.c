#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* left;
struct Node* right;
};
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
void dfs(struct Node* root) {
if (root == NULL) {
return;
}
printf("%d ", root->data);
dfs(root->left);
dfs(root->right);
}
int main() {
struct Node* root = createNode(1);
root->left = createNode(2);
root->right = createNode(3);
root->left->left = createNode(4);
root->left->right = createNode(5);
root->right->left = createNode(6);
root->right->right = createNode(7);
printf("DFS traversal of the tree: ");
dfs(root);
printf("\n");
return 0;
}
