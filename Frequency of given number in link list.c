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
int findFrequency(struct Node* head, int target) {
int frequency = 0;
struct Node* current = head;
while (current != NULL) {
if (current->data == target) {
frequency++;
}
current = current->next;
}
return frequency;
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
int value, target, numNodes;
printf("Enter the number of nodes in the linked list: ");
scanf("%d", &numNodes);
for (int i = 0; i < numNodes; i++) {
printf("Enter the value for node %d: ", i + 1);
scanf("%d", &value);
insert(&head, value);
}
display(head);
printf("Enter the number to find its frequency: ");
scanf("%d", &target);
int frequency = findFrequency(head, target);
printf("Frequency of %d in the linked list: %d\n", target, frequency);
return 0;
}
