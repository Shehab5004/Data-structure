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
void findMinMax(struct Node* head, int* min, int* max) {
if (head == NULL) {
printf("Linked list is empty.\n");
return;
}
*min = head->data;
*max = head->data;
struct Node* current = head->next;
while (current != NULL) {
if (current->data < *min) {
*min = current->data;
}
if (current->data > *max) {
*max = current->data;
}
current = current->next;
}
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
int value, min, max, numNodes;
printf("Enter the number of nodes in the linked list: ");
scanf("%d", &numNodes);
for (int i = 0; i < numNodes; i++) {
printf("Enter the value for node %d: ", i + 1);
scanf("%d", &value);
insert(&head, value);
}
display(head);
findMinMax(head, &min, &max);
printf("Smallest number: %d\n", min);
printf("Largest number: %d\n", max);
return 0;
}
