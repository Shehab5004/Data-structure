#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
void insert(struct Node** head, int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = *head;
*head = newNode;
}
void printEvenOdd(struct Node* head) {
struct Node* current = head;
if (current == NULL) {
printf("Linked list is empty.\n");
return;
}
printf("Even numbers: ");
while (current != NULL) {
if (current->data % 2 == 0) {
printf("%d ", current->data);
}
current = current->next;
}
printf("\n");
current = head;
printf("Odd numbers: ");
while (current != NULL) {
if (current->data % 2 != 0) {
printf("%d ", current->data);
}
current = current->next;
}
printf("\n");
}
void display(struct Node* head) {
struct Node* current = head;
if (current == NULL) {
printf("Linked list is empty.\n");
return;
}
printf("Linked list: ");
while (current != NULL) {
printf("%d ", current->data);
current = current->next;
}
printf("\n");
}
int main() {
struct Node* head = NULL;
int value, numNodes;
printf("Enter the number of nodes in the linked list: ");
scanf("%d", &numNodes);
for (int i = 0; i < numNodes; i++) {
printf("Enter the value for node %d: ", i + 1);
scanf("%d", &value);
insert(&head, value);
}
display(head);
printEvenOdd(head);
return 0;
}
